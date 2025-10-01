#include <stdio.h>
int main() {
    int arr[10];
    int num[42] = { 0 };
    int index = 0, count = 0;
    for (int i = 0; i < 10; i++) {
        scanf_s("%d", &arr[i]);
        num[arr[i] % 42] = 1;
    }
    for (int i = 0; i < 42; i++) {
        if (num[i] == 1)
            count++;
    }
    printf("%d", count);
}
