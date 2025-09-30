#include <stdio.h>
#include <stdlib.h>
int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int *coin = (int *)malloc(sizeof(int) * N);
    for(int i=0; i<N; i++){
        scanf("%d", &coin[i]);
    }
    int index=0;
    while(K<coin[index]){ 
        index++;
    }
    index--;

    
}