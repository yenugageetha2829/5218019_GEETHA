
#include <stdio.h>

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    int zeroBits = 0;
    unsigned long long temp = n;
    while (temp) {
        if ((temp & 1) == 0)
            zeroBits++;
        temp >>= 1;
    }
    unsigned long long result = (n == 0) ? 1 : 1ULL << zeroBits;
    printf("%llu\n", result);
    return 0;
}
