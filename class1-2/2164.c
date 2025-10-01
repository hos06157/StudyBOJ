#include <stdio.h>

int queue[1000001];
int front = 0, rear = 0;

void push(int x) {
    queue[rear++] = x;
}
int pop() {
    return queue[front++];
}
int size() {
    return rear - front;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) push(i);

    while (size() > 1) {
        pop();              // �� �� ī�� ������
        push(pop());        // ���� ī�� �� �ڷ� ������
    }

    printf("%d\n", pop());  // ������ ī�� ���
    return 0;
}
