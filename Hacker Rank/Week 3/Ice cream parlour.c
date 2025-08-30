#include <stdio.h>

void icecreamParlor(int m, int n, int cost[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i] + cost[j] == m) {
                printf("%d %d\n", i + 1, j + 1); // 1-based indexing
                return; // Only one unique solution, so we can stop
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int m, n;
        scanf("%d", &m);
        scanf("%d", &n);

        int cost[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &cost[i]);
        }

        icecreamParlor(m, n, cost);
    }

    return 0;
}