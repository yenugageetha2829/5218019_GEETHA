
#include <stdio.h>

int countSockPairs(int n, int socks[]) {
    int colorCount[101] = {0};
    int totalPairs = 0;
    // Count the number of socks for each color
    for (int i = 0; i < n; i++) {
        colorCount[socks[i]]++;
    }
    // Calculate pairs: two socks make one pair
    for (int color = 1; color <= 100; color++) {
        totalPairs += colorCount[color] / 2;
    }

    return totalPairs;
}

int main() {
    int n;
    scanf("%d", &n);
    int socks[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &socks[i]);
    }
    int result = countSockPairs(n, socks);
    printf("%d\n", result); 
    return 0;
}
