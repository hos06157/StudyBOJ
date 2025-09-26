#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

int queue[MAX_SIZE];
int front_val = 0, rear_val = 0;

void push(int x) {
    queue[rear_val++] = x;
}

int pop() {
    if (front_val == rear_val) return -1;
    return queue[front_val++];
}

int size() {
    return rear_val - front_val;
}

int empty() {
    return front_val == rear_val ? 1 : 0;
}

int front() {
    if (front_val == rear_val) return -1;
    return queue[front_val];
}

int back() {
    if (front_val == rear_val) return -1;
    return queue[rear_val - 1];
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
        else if (strcmp(command, "front") == 0) {
            printf("%d\n", front());
        }
        else if (strcmp(command, "back") == 0) {
            printf("%d\n", back());
        }
    }
    return 0;
}