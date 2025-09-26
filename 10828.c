#include <stdio.h>
#include <string.h>
#define MAX 100000

int stack[MAX];
int Top = -1;

void push(int x) {
    stack[++Top] = x;
}

int pop() {
    if (Top == -1) return -1;
    return stack[Top--];
}

int size() {
    return Top + 1;
}

int empty() {
    return Top == -1 ? 1 : 0;
}

int top() {
    if (Top == -1) return -1;
    return stack[Top];
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "push") == 0) {
            int value;
            scanf("%d", &value);
            push(value);
        }
        else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop());
        }
        else if (strcmp(command, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(command, "top") == 0) {
            printf("%d\n", top());
        }
    }
    return 0;
}