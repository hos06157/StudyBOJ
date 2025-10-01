#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

int cmp(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;

    if (p1->y != p2->y)
        return p1->y - p2->y;
    return p1->x - p2->x;
}

int main() {
    int N;
    scanf("%d", &N);

    Point* arr = (Point*)malloc(N * sizeof(Point));

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    qsort(arr, N, sizeof(Point), cmp);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }

    free(arr);
    return 0;
}
