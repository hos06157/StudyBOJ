#include <stdio.h>
#include <stdlib.h>  // malloc, free
int main() {
    int N;
    int sum = 0;
    char* S;
    scanf_s("%d", &N);

    S = (char*)malloc((N + 1) * sizeof(char));
    if (S == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    scanf_s("%s", S, N + 1);
    for (int i = 0; i < N; i++) {
        sum += S[i] - '0';
    }

    printf("%d", sum);

    free(S);
    return 0;
}
