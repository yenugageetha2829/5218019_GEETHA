
#include <stdio.h>
#include <stdlib.h>

// Union-Find data structure for connected components
int parent[100005];
int size[100005];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        if (size[px] < size[py]) {
            int temp = px;
            px = py;
            py = temp;
        }
        parent[py] = px;
        size[px] += size[py];
    }
}

long long roadsAndLibraries(int n, int c_lib, int c_road, int cities[][2], int m) {
    // If library cost <= road cost, build library in each city
    if (c_lib <= c_road) {
        return (long long)n * c_lib;
    }
    
    // Initialize Union-Find
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    
    // Union cities connected by roads
    for (int i = 0; i < m; i++) {
        unite(cities[i][0], cities[i][1]);
    }
    
    // Count connected components
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            components++;
        }
    }
    
    // For each component: 1 library + (component_size - 1) roads
    long long total_cost = (long long)components * c_lib + (long long)(n - components) * c_road;
    
    return total_cost;
}

int main() {
    int q;
    scanf("%d", &q);
    
    while (q--) {
        int n, m, c_lib, c_road;
        scanf("%d %d %d %d", &n, &m, &c_lib, &c_road);
        
        int cities[m][2];
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &cities[i][0], &cities[i][1]);
        }
        
        printf("%lld\n", roadsAndLibraries(n, c_lib, c_road, cities, m));
    }
    
    return 0;
}
