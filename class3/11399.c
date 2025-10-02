#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(){
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * N);
    for(int i=0; i< N; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
    int sum=0;
    int outp=0;
    for(int i=0; i<N; i++){
        sum+=arr[i];
        outp+=sum;
    }
    printf("%d", outp);
    return 0;
}