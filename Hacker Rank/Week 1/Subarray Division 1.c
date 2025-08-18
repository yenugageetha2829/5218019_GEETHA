#include <stdio.h>

int birthday(int s[], int n, int d, int m) {
    int count = 0;
    // check every subarray of length m
    for (int i = 0; i <= n - m; i++) {
        int sum = 0;
        // calculate sum of subarray s[i ... i+m-1]
        for (int j = 0; j < m; j++) {
            sum += s[i + j];
        }
        if (sum == d) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n); // size of chocolate bar
    
    int s[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    
    int d, m;
    scanf("%d %d", &d, &m); // Ron's day and month
    
    int result = birthday(s, n, d, m);
    printf("%d\n", result);
    
    return 0;
}