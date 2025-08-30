
#include <stdio.h>

int pageCount(int totalPages, int targetPage) {
    int frontTurns = 0, backTurns = 0;

    // Count from the front
    for (int i = 1; i < targetPage; i += 2) {
        frontTurns++;
    }

    // Count from the back
    if (totalPages % 2 == 0) {
        for (int i = totalPages; i > targetPage; i -= 2) {
            backTurns++;
        }
    } else {
        for (int i = totalPages - 1; i > targetPage; i -= 2) {
            backTurns++;
        }
    }

    return (frontTurns < backTurns) ? frontTurns : backTurns;
}

int main() {
    int n, p;
    scanf("%d%d", &n, &p);

    int result = pageCount(n, p);
    printf("%d\n", result);

    return 0;
}

