
#include <stdio.h>
#include <stdlib.h>

// Custom comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxMin(int k, int arr[], int n) {
    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int minUnfairness = __INT_MAX__;  // Large initial value

    // Slide a window of size k
    for (int i = 0; i + k - 1 < n; i++) {
        int currentUnfairness = arr[i + k - 1] - arr[i];
        if (currentUnfairness < minUnfairness) {
            minUnfairness = currentUnfairness;
        }
    }

    return minUnfairness;
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxMin(k, arr, n);
    printf("%d\n", result);

    return 0;
}
