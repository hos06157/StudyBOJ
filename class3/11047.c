#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int *coin = (int *)malloc(sizeof(int) * N);
    for(int i=0; i<N; i++){
        scanf("%d", &coin[i]);
    }

    int c = 0;
    for(int i = N-1; i >= 0; i--){  
            if(coin[i] <= K){
            c += K / coin[i];
            K = K % coin[i];
        }
    }
    printf("%d", c);

    free(coin);
    return 0;
}