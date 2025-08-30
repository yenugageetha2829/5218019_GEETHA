#include <stdio.h>
#include <stdlib.h>

void maxSubarray(int arr[], int n) {
    int maxSubArr = arr[0];
    int currentSum = arr[0];

    int maxSubSeq = arr[0];
    if (maxSubSeq < 0) maxSubSeq = arr[0];

    // Initialize subsequence sum
    if (arr[0] > 0) maxSubSeq = arr[0];
    else maxSubSeq = arr[0];

    for (int i = 1; i < n; i++) {
        // Kadane's algorithm for subarray
        if (currentSum + arr[i] > arr[i])
            currentSum += arr[i];
        else
            currentSum = arr[i];

        if (currentSum > maxSubArr)
            maxSubArr = currentSum;

        // For subsequence: sum positives or take max element if all negative
        if (arr[i] > 0) {
            if (maxSubSeq > 0) maxSubSeq += arr[i];
            else maxSubSeq = arr[i];
        } else if (maxSubSeq < arr[i]) {
            maxSubSeq = arr[i];
        }
    }

    printf("%d %d\n", maxSubArr, maxSubSeq);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        maxSubarray(arr, n);
        free(arr);
    }

    return 0;
}