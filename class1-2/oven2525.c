#include <stdio.h>

int main() {
    int hour, minute, a;
    scanf_s("%d %d", &hour, &minute);
    scanf_s("%d", &a);
    minute += a;
    if (minute >= 60) {
        hour = hour + (minute / 60);
        if (hour > 23) hour = hour - 24;
        minute = minute % 60;

    }
    printf("%d %d\n", hour, minute);

    return 0;
}

