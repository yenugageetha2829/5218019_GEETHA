
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicList;

// Initialize a dynamic list
void initList(DynamicList *list) {
    list->data = (int *)malloc(2 * sizeof(int));
    list->size = 0;
    list->capacity = 2;
}

// Append value to the dynamic list
void append(DynamicList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    DynamicList *seqList = (DynamicList *)malloc(n * sizeof(DynamicList));

    for (int i = 0; i < n; i++) {
        initList(&seqList[i]);
    }

    int lastAnswer = 0;
    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            append(&seqList[idx], y);
        } else if (type == 2) {
            int pos = y % seqList[idx].size;
            lastAnswer = seqList[idx].data[pos];
            printf("%d\n", lastAnswer);
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(seqList[i].data);
    }
    free(seqList);

    return 0;
}
