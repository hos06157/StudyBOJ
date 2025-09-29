#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int priority;
    int index;
} Document;

typedef struct {
    int front, rear, size, capacity;
    Document* data;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = capacity - 1;
    q->size = 0;
    q->data = (Document*)malloc(capacity * sizeof(Document));
    return q;
}

int isEmpty(Queue* q) {
    return (q->size == 0);
}

void enqueue(Queue* q, Document item) {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = item;
    q->size++;
}

Document dequeue(Queue* q) {
    Document item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        Queue* q = createQueue(N);

        for (int i = 0; i < N; i++) {
            int p;
            scanf("%d", &p);
            Document doc = {p, i};
            enqueue(q, doc);
        }

        int count = 0;
        while (!isEmpty(q)) {
            Document curr = dequeue(q);
            int hasHigher = 0;

            for (int i = 0; i < q->size; i++) {
                int idx = (q->front + i) % q->capacity;
                if (q->data[idx].priority > curr.priority) {
                    hasHigher = 1;
                    break;
                }
            }

            if (hasHigher) {
                enqueue(q, curr);
            } else {
                count++;
                if (curr.index == M) {
                    printf("%d\n", count);
                    break;
                }
            }
        }
        free(q->data);
        free(q);
    }
    return 0;
}
