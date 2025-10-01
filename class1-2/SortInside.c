#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(char*)b - *(char*)a);
}

int main() {
    char num[101];
    if (fgets(num, sizeof(num), stdin) == NULL) return 1;

    int len = strlen(num);
    if (num[len - 1] == '\n') num[--len] = '\0';

    qsort(num, len, sizeof(char), cmp);

    printf("%s\n", num);
    return 0;
}
