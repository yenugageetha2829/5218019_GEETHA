#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n, k;
    char s[105];

    // Input length of string
    scanf("%d", &n);

    // Input string
    scanf("%s", s);

    // Input rotation factor
    scanf("%d", &k);

    // To handle cases where k > 26
    k = k % 26;

    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            if (isupper(s[i])) {
                s[i] = 'A' + (s[i] - 'A' + k) % 26;
            } else {
                s[i] = 'a' + (s[i] - 'a' + k) % 26;
            }
        }
        // Non-alphabetic characters remain unchanged
    }

    printf("%s\n", s);

    return 0;
}
