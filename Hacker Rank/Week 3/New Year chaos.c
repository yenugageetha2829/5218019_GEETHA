
#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int q[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &q[i]);
        int total = 0, chaotic = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (q[i] - (i + 1) > 2) {
                chaotic = 1;
                break;
            }
            // Only need to look up two positions ahead of q[i]'s original position
            int j = (q[i] - 2 > 0) ? q[i] - 2 : 0;
            for (; j < i; j++)
                if (q[j] > q[i])
                    total++;
        }
        if (chaotic)
            printf("Too chaotic\n");
        else
            printf("%d\n", total);
    }
    return 0;
}
