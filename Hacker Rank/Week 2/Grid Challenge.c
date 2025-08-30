
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sort characters in a string using bubble sort (custom, to reduce plagiarism)
void sortString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

// Function to check if grid columns are sorted
int isColumnSorted(char **grid, int n) {
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n - 1; row++) {
            if (grid[row][col] > grid[row + 1][col]) {
                return 0; // Not sorted
            }
        }
    }
    return 1; // Sorted
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char **grid = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++) {
            grid[i] = (char *)malloc((n + 1) * sizeof(char));
            scanf("%s", grid[i]);
            sortString(grid[i]); // Sort each row
        }

        if (isColumnSorted(grid, n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

        // Free allocated memory
        for (int i = 0; i < n; i++) {
            free(grid[i]);
        }
        free(grid);
    }

    return 0;
}
