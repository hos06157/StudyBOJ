#include <stdio.h>
#include <string.h>

int main() {
    char buffer[105];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[0] == '.' && buffer[1] == '\n') break;

        char stack[105];
        int top = 0, flag = 1;

        for (int i = 0; buffer[i]; i++) {
            if (buffer[i] == '(' || buffer[i] == '[') {
                stack[top++] = buffer[i];
            }
            else if (buffer[i] == ')') {
                if (top > 0 && stack[top - 1] == '(') {
                    top--;
                }
                else {
                    flag = 0;
                    break;
                }
            }
            else if (buffer[i] == ']') {
                if (top > 0 && stack[top - 1] == '[') {
                    top--;
                }
                else {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag && top == 0) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
