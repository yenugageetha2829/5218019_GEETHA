
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX];
int size = 0;

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up after insertion
void bubbleUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

// Heapify down after deletion
void bubbleDown(int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != index) {
            swap(&heap[smallest], &heap[index]);
            index = smallest;
        } else break;
    }
}

// Insert into heap
void insert(int x) {
    heap[size] = x;
    bubbleUp(size);
    size++;
}

// Find element index in heap
int findIndex(int x) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == x) return i;
    }
    return -1;
}

// Delete element from heap
void deleteElement(int x) {
    int index = findIndex(x);
    if (index == -1) return; // Not found
    heap[index] = heap[size - 1];
    size--;
    bubbleDown(index);
}

// Print minimum element
void printMin() {
    if (size > 0) printf("%d\n", heap[0]);
}

int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (type == 2) {
            int x;
            scanf("%d", &x);
            deleteElement(x);
        } else if (type == 3) {
            printMin();
        }
    }
    return 0;
}
