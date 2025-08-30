
#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char data[MAX];
    int top;
} Stack;

void push(Stack *s, char ch) {
    s->data[++(s->top)] = ch;
}

char pop(Stack *s) {
    return s->data[(s->top)--];
}

char peek(Stack *s) {
    return s->data[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isBalanced(char *str) {
    Stack stack;
    stack.top = -1;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else {
            if (isEmpty(&stack)) return 0;

            char topChar = peek(&stack);
            if ((ch == ')' && topChar == '(') ||
                (ch == '}' && topChar == '{') ||
                (ch == ']' && topChar == '[')) {
                pop(&stack);
            } else {
                return 0;
            }
        }
    }
    return isEmpty(&stack);
}

int main() {
    int n;
    scanf("%d", &n);
    char str[MAX];

    while (n--) {
        scanf("%s", str);
        if (isBalanced(str)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
