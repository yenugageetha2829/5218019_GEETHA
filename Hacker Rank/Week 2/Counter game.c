
#include <stdio.h>

unsigned long long highestPowerOf2(unsigned long long n) {
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    n |= (n >> 32);
    return n - (n >> 1);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);
        int moves = 0;
        while (n > 1) {
            if ((n & (n - 1)) == 0) {
                n >>= 1;
            } else {
                n -= highestPowerOf2(n);
            }
            moves++;
        }
        printf("%s\n", (moves % 2 == 0) ? "Richard" : "Louise");
    }
    return 0;
}
