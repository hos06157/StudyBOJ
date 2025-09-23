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
        pop();              // 맨 위 카드 버리기
        push(pop());        // 다음 카드 맨 뒤로 보내기
    }

    printf("%d\n", pop());  // 마지막 카드 출력
    return 0;
}
