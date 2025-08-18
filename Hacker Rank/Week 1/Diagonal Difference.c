#include <stdio.h>
#include <stdlib.h>  // for abs() function

// Function to calculate diagonal difference
int diagonalDifference(int n, int arr[n][n]) {
    int primary = 0;   // sum of primary diagonal
    int secondary = 0; // sum of secondary diagonal

    for (int i = 0; i < n; i++) {
        primary += arr[i][i];           // elements where row == column
        secondary += arr[i][n - i - 1]; // elements where row + col = n-1
    }

    return abs(primary - secondary); // absolute difference
}

int main() {
    int n;
    scanf("%d", &n); // size of the matrix

    int matrix[n][n];

    // Read the matrix values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Call function and print result
    int result = diagonalDifference(n, matrix);
    printf("%d\n", result);

    return 0;
}