#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char s[n + 1];
    scanf("%s", s);

    int changes[n];
    memset(changes, 0, sizeof(changes));

    int needed = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            needed++;
            changes[i] = changes[n - 1 - i] = 1;
        }
    }

    if (needed > k) {
        printf("-1\n");
        return 0;
    }

    int rem = k;

    // Step 1: Make palindrome with minimal changes
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            char maxc = s[i] > s[n - 1 - i] ? s[i] : s[n - 1 - i];
            s[i] = s[n - 1 - i] = maxc;
            rem--;
        }
    }

    // Step 2: Maximize digits to '9' if changes remain
    for (int i = 0; i < n / 2 && rem > 0; i++) {
        if (s[i] != '9') {
            if (changes[i] && rem >= 1) {
                s[i] = s[n - 1 - i] = '9';
                rem--;
            } else if (!changes[i] && rem >= 2) {
                s[i] = s[n - 1 - i] = '9';
                rem -= 2;
            }
        }
    }

    // For odd length, maximize the middle digit if changes remain
    if (n % 2 == 1 && rem > 0) {
        s[n / 2] = '9';
    }

    printf("%s\n", s); // Output highest value palindrome
    return 0;
}