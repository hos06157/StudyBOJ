#include <stdio.h>
#include <string.h>

int main() {
    char buffer[51];
    int N;
    scanf("%d", &N);
    getchar();

    while (N--) {
		scanf("%s", buffer);
        int top = 0;
        int valid = 1;

        for (int i = 0; buffer[i]; i++) {
            if (buffer[i] == '(') {
                top++;
            }
            else if (buffer[i] == ')') {
                if (top > 0) top--;
                else { 
					valid = 0;
                    break;
                }
            }
        }

        if (valid && top == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
