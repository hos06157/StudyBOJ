#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int value) {
    if (!is_full(s)) {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (!is_empty(s)) {
        return s->data[(s->top)--];
    }
    return -1; 
}

int peek(Stack *s) {
    if (!is_empty(s)) {
        return s->data[s->top];
    }
    return -1; 
}

int main() {
    Stack arr;
    init(&arr);

    int N;
    scanf("%d", &N);

    int* seq = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) scanf("%d", &seq[i]);

    char** output = (char**)malloc(sizeof(char*) * MAX_SIZE * 2);
    int out_idx = 0;

    int current = 1;
    for (int i = 0; i < N; i++) {
        int target = seq[i];
        while (current <= target) {
            push(&arr, current++);
            output[out_idx++] = "+\n";
        }
        if (peek(&arr) == target) {
            pop(&arr);
            output[out_idx++] = "-\n";
        } else {
            printf("NO\n");
            free(seq);
            free(output);
            return 0;
        }
    }

    for (int i = 0; i < out_idx; i++)
        printf("%s", output[i]);

    free(seq);
    free(output);
    return 0;
}