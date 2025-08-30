
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

long modPow(long base, int exp) {
    long result = 1;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

void legoBlocks(int n, int m) {
    long rowWays[m + 1];
    rowWays[0] = 1;

    // Step 1: Compute ways to build a single row
    for (int i = 1; i <= m; i++) {
        rowWays[i] = 0;
        for (int b = 1; b <= 4; b++) {
            if (i - b >= 0) {
                rowWays[i] = (rowWays[i] + rowWays[i - b]) % MOD;
            }
        }
    }

    // Step 2: Compute total ways for full wall (no cracks considered)
    long total[m + 1];
    for (int i = 1; i <= m; i++) {
        total[i] = modPow(rowWays[i], n);
    }

    // Step 3: Compute valid configurations using inclusion-exclusion
    long valid[m + 1];
    valid[0] = 0;
    for (int width = 1; width <= m; width++) {
        long temp = total[width];
        for (int cut = 1; cut < width; cut++) {
            temp = (temp - (valid[cut] * total[width - cut]) % MOD + MOD) % MOD;
        }
        valid[width] = temp;
    }

    printf("%ld\n", valid[m]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        legoBlocks(n, m);
    }
    return 0;
}
