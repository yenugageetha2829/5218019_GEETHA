#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000010

long long arr[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long k;
        scanf("%d %d %lld", &a, &b, &k);

        arr[a] += k;
        arr[b + 1] -= k;
    }

    long long max = 0, temp = 0;
    for (int i = 1; i <= n; i++) {
        temp += arr[i];
        if (temp > max) max = temp;
    }

    printf("%lld\n", max);
    return 0;
}