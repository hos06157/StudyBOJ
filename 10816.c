#include <stdio.h>

int main(){
    int N, M;
    scanf("%d", &N);
    int arr[20000001] = {0};
    for(int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);
        arr[num+10000000]++;
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int num;
        scanf("%d", &num);
        printf("%d ", arr[num+10000000]);
    }
    return 0;
}