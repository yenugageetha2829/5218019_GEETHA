
#include <stdio.h>
#include <string.h>

long long digitSum(const char *s) {
    long long sum = 0;
    for (int i = 0; s[i]; i++)
        sum += s[i] - '0';
    return sum;
}

long long recursiveSuperDigit(long long x) {
    while (x >= 10) {
        long long temp = 0;
        while (x > 0) {
            temp += x % 10;
            x /= 10;
        }
        x = temp;
    }
    return x;
}

int main() {
    char n[100005];
    int k;
    scanf("%s %d", n, &k);
    long long baseSum = digitSum(n);
    long long totalSum = baseSum * k;
    long long result = recursiveSuperDigit(totalSum);
    printf("%lld\n", result);
    return 0;
}
