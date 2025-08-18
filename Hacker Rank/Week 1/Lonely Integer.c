#include <stdio.h>

// Function to find the lonely integer
int lonelyinteger(int arr[], int n) {
    int result = 0;
    
    // XOR all numbers together
    // Since x ^ x = 0 and x ^ 0 = x,
    // all duplicate numbers cancel out
    // leaving only the unique number.
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    
    return result;  // return the unique element
}

int main() {
    int n;
    
    // Read the size of the array
    scanf("%d", &n);
    
    int values[n];
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    
    // Call the function to find the lonely integer
    int unique = lonelyinteger(values, n);
    
    // Print the result
    printf("%d\n", unique);
    
    return 0;
}