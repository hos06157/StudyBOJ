#include <stdio.h>

int stack[100000];
int top = -1;

void push(int value) {
    stack[++top] = value;
}
void pop() {
    if (top != -1) top--;
}
void sum() {
    int total = 0;
    for (int i=0; i<=top; i++) total += stack[i];
    printf("%d", total);
}
int main() {
    int K;
    scanf("%d", &K);
    for (int i=0; i<K; i++){
        int num;
        scanf("%d", &num);
        if(num == 0) pop();
        else push(num);
    }
    sum();
    return 0;
}