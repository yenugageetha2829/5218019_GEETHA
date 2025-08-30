
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        long long total = 0, left = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            total += arr[i];
        }
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (left == total - left - arr[i]) {
                found = 1;
                break;
            }
            left += arr[i];
        }
        printf(found ? "YES\n" : "NO\n");
    }
    return 0;
}
