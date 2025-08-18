#include <stdio.h>

// Function to flip 32-bit unsigned integer using bitwise NOT and masking
unsigned int flippingBits(unsigned int n) {
    // ~n flips all bits of n
    // & 0xFFFFFFFF ensures only lower 32 bits are kept
    return (~n) & 0xFFFFFFFF;
}

int main() {
    int q;
    scanf("%d", &q);  // number of test cases

    for (int i = 0; i < q; i++) {
        unsigned int n;
        scanf("%u", &n);  // read unsigned integer

        unsigned int result = flippingBits(n);
        printf("%u\n", result);  // print flipped value
    }

    return 0;
}