#include <stdio.h>
#include <string.h>

int main() {
    char S[101];
    int alpha[26];
    for (int i = 0; i < 26; i++) {
        alpha[i] = -1;
    }
    scanf_s("%s", S, 101);
    int len = strlen(S);

    for (int i = 0; i < len; i++) {
        int idx = S[i] - 'a';
        if (alpha[idx] == -1) {
            alpha[idx] = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%d ", alpha[i]);
    }
    return 0;
}
