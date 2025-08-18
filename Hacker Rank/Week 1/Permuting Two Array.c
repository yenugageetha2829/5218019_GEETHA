#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort (ascending)
int cmpAsc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Comparison function for qsort (descending)
int cmpDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Function to check if valid permutation exists
const char* twoArrays(int n, int k, int A[], int B[]) {
    // Sort A in ascending order
    qsort(A, n, sizeof(int), cmpAsc);
    // Sort B in descending order
    qsort(B, n, sizeof(int), cmpDesc);

    // Check condition A[i] + B[i] >= k
    for (int i = 0; i < n; i++) {
        if (A[i] + B[i] < k) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int q;
    scanf("%d", &q); // number of queries

    while (q--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int A[n], B[n];
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        for (int i = 0; i < n; i++) scanf("%d", &B[i]);

        printf("%s\n", twoArrays(n, k, A, B));
    }

    return 0;
}