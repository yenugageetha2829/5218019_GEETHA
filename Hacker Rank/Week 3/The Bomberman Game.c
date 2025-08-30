
#include <stdio.h>
#include <string.h>

#define MAXN 205

int r, c, n;
char grid1[MAXN][MAXN], grid2[MAXN][MAXN], grid3[MAXN][MAXN];

// Mark explodes next state based on bombs in cur
void explode(char cur[][MAXN], char next[][MAXN]) {
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            next[i][j] = 'O';
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (cur[i][j] == 'O') {
                next[i][j] = '.';
                if (i > 0) next[i-1][j] = '.';
                if (i < r-1) next[i+1][j] = '.';
                if (j > 0) next[i][j-1] = '.';
                if (j < c-1) next[i][j+1] = '.';
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &r, &c, &n);
    for (int i = 0; i < r; ++i)
        scanf("%s", grid1[i]);

    if (n == 1) {
        for (int i = 0; i < r; ++i)
            printf("%s\n", grid1[i]);
    } else if (n % 2 == 0) {
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                grid2[i][j] = 'O';
        for (int i = 0; i < r; ++i)
            printf("%s\n", grid2[i]);
    } else {
        explode(grid1, grid2);       // State after first detonation
        explode(grid2, grid3);       // State after second detonation
        if ((n % 4) == 3) {
            for (int i = 0; i < r; ++i)
                printf("%s\n", grid2[i]);
        } else {
            for (int i = 0; i < r; ++i)
                printf("%s\n", grid3[i]);
        }
    }
    return 0;
}
