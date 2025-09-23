#include <stdio.h>
#include <stdlib.h> 

int main() {
    int N, M, x, y;
    scanf_s("%d %d", &N, &M);
    int* num = (int*)malloc(N * sizeof(int));
    if (num == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        num[i] = i + 1;
    }

    for (int i = 0; i < M; i++) {
        scanf_s("%d %d", &x, &y);
        x--; y--;
        while (x < y) {
            int temp = num[x];
            num[x] = num[y];
            num[y] = temp;
            x++; y--;
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", num[i]);
    }
    free(num);

    return 0;
}
