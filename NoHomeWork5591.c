#include <stdio.h>
int main() {
    int s[31] = { 0 };
    for (int i = 0; i < 28; i++) {
        int num;
        scanf_s("%d", &num);
        s[num] = 1;
    }
    for (int i = 1; i <= 30; i++) {
        if (s[i] == 0)
            printf("%d\n", i);
    }
    return 0;
}

