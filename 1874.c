#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// 스택 초기화
void init(Stack *s) {
    s->top = -1;
}

// 스택이 비었는지 확인
int is_empty(Stack *s) {
    return s->top == -1;
}

// 스택이 가득 찼는지 확인
int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// 스택에 값 추가 (push)
void push(Stack *s, int value) {
    if (!is_full(s)) {
        s->data[++(s->top)] = value;
    }
}

// 스택에서 값 제거 (pop)
int pop(Stack *s) {
    if (!is_empty(s)) {
        return s->data[(s->top)--];
    }
    return -1; // 오류: 스택이 비어있음
}

// 스택의 top 값 확인 (peek)
int peek(Stack *s) {
    if (!is_empty(s)) {
        return s->data[s->top];
    }
    return -1; // 오류: 스택이 비어있음
}