#include <stdio.h>
#include <string.h>

int main() {
    int M;
    scanf("%d", &M);
    int S = 0;  // 집합 초기화

    for(int i = 0; i < M; i++){
        char cmd[10];
        int x;
        scanf("%s", cmd);

        if(strcmp(cmd, "add") == 0){
            scanf("%d", &x);
            S |= (1 << (x-1));
        }
        else if(strcmp(cmd, "remove") == 0){
            scanf("%d", &x);
            S &= ~(1 << (x-1));
        }
        else if(strcmp(cmd, "check") == 0){
            scanf("%d", &x);
            if(S & (1 << (x-1))) printf("1\n");
            else printf("0\n");
        }
        else if(strcmp(cmd, "toggle") == 0){
            scanf("%d", &x);
            S ^= (1 << (x-1));
        }
        else if(strcmp(cmd, "all") == 0){
            S = (1 << 20) - 1;
        }
        else if(strcmp(cmd, "empty") == 0){
            S = 0;
        }
    }
    return 0;
}
