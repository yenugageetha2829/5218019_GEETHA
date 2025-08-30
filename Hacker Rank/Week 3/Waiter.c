#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Function to generate first 'q' primes
void generatePrimes(int primes[], int q) {
    int count = 0, num = 2;
    while (count < q) {
        int isPrime = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            primes[count++] = num;
        }
        num++;
    }
}

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    return s->data[(s->top)--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    Stack A, B;
    A.top = -1;
    B.top = -1;

    int numbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Push numbers into stack A in reverse (top is last element)
    for (int i = 0; i < n; i++) {
        push(&A, numbers[i]);
    }

    int primes[q];
    generatePrimes(primes, q);

    // Output array
    int *result = (int *)malloc(n * sizeof(int));
    int index = 0;

    for (int i = 0; i < q; i++) {
        Stack nextA;
        nextA.top = -1;

        while (!isEmpty(&A)) {
            int value = pop(&A);
            if (value % primes[i] == 0) {
                push(&B, value);
            } else {
                push(&nextA, value);
            }
        }

        while (!isEmpty(&B)) {
            result[index++] = pop(&B);
        }

        A = nextA; // Prepare for next iteration
    }

    while (!isEmpty(&A)) {
        result[index++] = pop(&A);
    }

    for (int i = 0; i < index; i++) {
        printf("%d\n", result[i]);
    }

    free(result);
    return 0;
}