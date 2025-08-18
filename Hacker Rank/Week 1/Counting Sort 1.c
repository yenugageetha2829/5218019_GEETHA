#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);   // number of items in input

    int freq[100] = {0}; // frequency array of size 100, all initialized to 0
    int value;

    // Read input and update frequency counts
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        freq[value]++;   // increase counter for this number
    }

    // Print the frequency array
    for (int i = 0; i < 100; i++) {
        printf("%d", freq[i]);
        if (i < 99) {
            printf(" ");  // space between numbers
        }
    }
    printf("\n");

    return 0;
}