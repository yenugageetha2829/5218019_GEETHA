
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000

// Min-Heap operations
void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

void heapify_down(int heap[], int n, int i) {
    while (1) {
        int smallest = i, left = 2*i+1, right = 2*i+2;
        if (left < n && heap[left] < heap[smallest]) smallest = left;
        if (right < n && heap[right] < heap[smallest]) smallest = right;
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void heapify_up(int heap[], int i) {
    while (i > 0 && heap[i] < heap[(i-1)/2]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extract_min(int heap[], int* n) {
    int min = heap[0];
    heap[0] = heap[--(*n)];
    heapify_down(heap, *n, 0);
    return min;
}

void insert(int heap[], int* n, int value) {
    heap[(*n)++] = value;
    heapify_up(heap, (*n)-1);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int heap[MAX_N], heap_size = n;
    for (int i = 0; i < n; i++) scanf("%d", &heap[i]);

    // Build initial heap
    for (int i = heap_size/2 - 1; i >= 0; i--) heapify_down(heap, heap_size, i);

    int steps = 0;
    while (heap_size > 1 && heap[0] < k) {
        int least = extract_min(heap, &heap_size);
        int second_least = extract_min(heap, &heap_size);
        int new_sweet = least + 2 * second_least;
        insert(heap, &heap_size, new_sweet);
        steps++;
    }

    if (heap_size && heap[0] >= k)
        printf("%d\n", steps);
    else
        printf("-1\n");

    return 0;
}
