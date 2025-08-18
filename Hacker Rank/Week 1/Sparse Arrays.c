#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001   // max string length (safe buffer)

int main() {
    int n, q;
    scanf("%d", &n);   // number of input strings

    char strings[n][MAX_LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    scanf("%d", &q);   // number of queries
    char queries[q][MAX_LEN];

    for (int i = 0; i < q; i++) {
        scanf("%s", queries[i]);
    }

    // For each query, count frequency in input strings
    for (int i = 0; i < q; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(queries[i], strings[j]) == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}