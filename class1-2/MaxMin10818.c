#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, max, min;
    scanf_s("%d", &a);
    int* num = (int*)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) {
        scanf_s("%d", &num[i]);
    }
    max = num[0];
    min = num[0];
    for (int i = 1; i < a; i++) {
        if (num[i] > max) max = num[i];
        if (num[i] < min) min = num[i];
    }
    printf("%d %d", min, max);
    free(num);
    return 0;
}
