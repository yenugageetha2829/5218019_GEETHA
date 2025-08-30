
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    int index;
} Pair;

int cmp(const void* a, const void* b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

int min_swaps(int arr[], int n, int reverse) {
    Pair pairs[n];
    for (int i = 0; i < n; i++) {
        pairs[i].value = arr[i];
        pairs[i].index = i;
    }
    // Sort pairs: ascending or descending
    if (reverse) {
        for (int i = 0; i < n; i++)
            pairs[i].value = -pairs[i].value;
    }
    qsort(pairs, n, sizeof(Pair), cmp);

    int visited[n];
    memset(visited, 0, sizeof(visited));
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || pairs[i].index == i)
            continue;
        int cycle = 0, j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = pairs[j].index;
            cycle++;
        }
        if (cycle > 0)
            swaps += cycle - 1;
    }
    return swaps;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int a = min_swaps(arr, n, 0);
    int d = min_swaps(arr, n, 1);
    printf("%d\n", a < d ? a : d);
    return 0;
}
