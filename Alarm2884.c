#include <stdio.h>

int main() {
    int hour, minute;
    scanf_s("%d %d", &hour, &minute);

    if (minute >= 45) {
        minute -= 45;
    }
    else {
        minute += 15;
        if (hour == 0)
            hour = 23;
        else
            hour -= 1;
    }
    printf("%d %d\n", hour, minute);

    return 0;
}

