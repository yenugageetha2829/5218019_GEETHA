#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);
    int ranked[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &ranked[i]);
    scanf("%d", &m);
    int player[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &player[i]);
    
    // Remove duplicates from ranked
    int unique[n], k = 0;
    unique[k++] = ranked[0];
    for (int i = 1; i < n; i++)
        if (ranked[i] != ranked[i - 1])
            unique[k++] = ranked[i];

    // For each player's score, find their rank
    for (int i = 0; i < m; i++) {
        int score = player[i];
        while (k > 0 && score >= unique[k - 1])
            k--;
        printf("%d\n", k + 1);
    }
    return 0;
}