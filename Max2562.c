#include <stdio.h>

int main() {
    int num[9], max = 0, idx = 0;
    for (int i = 0; i < 9; i++) {
        scanf_s("%d", &num[i]);
        if (num[i] > max || i == 0) {
            max = num[i];
            idx = i + 1;
        }
    }
    printf("%d\n%d", max, idx);
    return 0;
}
