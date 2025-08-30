#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000000

// Structure for storing undo operations
typedef struct {
    int type; // 1 for append, 2 for delete
    char* str;
} Operation;

// Stack for undo history
Operation history[MAX_LEN];
int top = -1;

// String implementation
char S[MAX_LEN + 1];
int curr_len = 0;

// Push operation to history stack
void push(int type, const char* str) {
    history[++top].type = type;
    history[top].str = strdup(str);
}

// Pop from history stack
Operation pop() {
    return history[top--];
}

int main() {
    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        int t;
        scanf("%d", &t);

        if (t == 1) {
            // Append
            char W[MAX_LEN + 1];
            scanf("%s", W);
            push(1, W);
            int l = strlen(W);
            memcpy(S + curr_len, W, l);
            curr_len += l;
            S[curr_len] = '\0';
        } else if (t == 2) {
            // Delete
            int k;
            scanf("%d", &k);
            push(2, S + curr_len - k);
            curr_len -= k;
            S[curr_len] = '\0';
        } else if (t == 3) {
            // Print
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);
        } else if (t == 4) {
            // Undo
            if (top < 0) continue;
            Operation op = pop();
            if (op.type == 1) {
                // Undo append
                int l = strlen(op.str);
                curr_len -= l;
                S[curr_len] = '\0';
            } else if (op.type == 2) {
                // Undo delete
                int l = strlen(op.str);
                memcpy(S + curr_len, op.str, l);
                curr_len += l;
                S[curr_len] = '\0';
            }
            free(op.str);
        }
    }
    return 0;
}