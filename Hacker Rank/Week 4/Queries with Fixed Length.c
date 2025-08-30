
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int arr[MAXN], qarr[105];

// Deque structure for sliding window maximum
int deque[MAXN], front, back;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < q; i++)
        scanf("%d", &qarr[i]);

    for (int t = 0; t < q; t++) {
        int d = qarr[t];
        int minmax = 1000001;

        front = back = 0;
        for (int i = 0; i < n; i++) {
            // Remove elements outside window from front
            while (front < back && deque[front] <= i - d)
                front++;
            // Remove smaller values from back
            while (front < back && arr[deque[back - 1]] <= arr[i])
                back--;
            deque[back++] = i;
            // When window is fully inside array
            if (i >= d - 1) {
                int currmax = arr[deque[front]];
                if (currmax < minmax)
                    minmax = currmax;
            }
        }
        printf("%d\n", minmax);
    }
    return 0;
}
