#include <stdio.h>

int towerBreakers(int towers, int height) {
    int winner;
    
    if (height == 1) {
        // No move possible, second player wins
        winner = 2;
    } else if (towers % 2 == 0) {
        // Even number of towers, second player mirrors first
        winner = 2;
    } else {
        // Odd number of towers and height > 1, first player wins
        winner = 1;
    }
    
    return winner;
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    
    while (testCases > 0) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        int result = towerBreakers(n, m);
        printf("%d\n", result);
        
        testCases--;
    }
    
    return 0;
}
