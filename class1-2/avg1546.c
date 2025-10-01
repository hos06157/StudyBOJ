
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int max = 0;
    double M = 0;
    scanf_s("%d", &N);
    int* num = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf_s("%d", &num[i]);
        if (max < num[i]) max = num[i];
    }
    for (int i = 0; i < N; i++) {
        M += num[i] / (double)max * 100;
    }
    printf("%f", M / N);
    free(num);
    return 0;
}