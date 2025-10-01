#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    int* num = (int*)malloc(N * sizeof(int));
    if (num == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }
    qsort(num, N, sizeof(int), compare);

    for (int i = 0; i < N; i++) {
        printf("%d\n", num[i]);
    }
    free(num);
    return 0;
}
