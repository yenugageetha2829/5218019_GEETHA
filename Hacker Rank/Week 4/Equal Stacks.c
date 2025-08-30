
#include <stdio.h>
#include <stdlib.h>

// Function to calculate sum of an array
int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int *h1 = (int *)malloc(n1 * sizeof(int));
    int *h2 = (int *)malloc(n2 * sizeof(int));
    int *h3 = (int *)malloc(n3 * sizeof(int));

    for (int i = 0; i < n1; i++) scanf("%d", &h1[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &h2[i]);
    for (int i = 0; i < n3; i++) scanf("%d", &h3[i]);

    // Calculate initial sums
    int sum1 = sumArray(h1, n1);
    int sum2 = sumArray(h2, n2);
    int sum3 = sumArray(h3, n3);

    int i = 0, j = 0, k = 0;

    // Reduce stacks until all sums are equal or any stack is empty
    while (!(sum1 == sum2 && sum2 == sum3)) {
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[j++];
        } else {
            sum3 -= h3[k++];
        }

        if (i == n1 || j == n2 || k == n3) {
            // One stack is empty, so max equal height is 0
            printf("0\n");
            free(h1); free(h2); free(h3);
            return 0;
        }
    }

    printf("%d\n", sum1);

    free(h1);
    free(h2);
    free(h3);
    return 0;
}
