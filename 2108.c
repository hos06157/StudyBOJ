#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arithmetic_mean(int* arr, int N){ // 산술평균
    int sum=0;
    for (int i=0; i<N; i++){
        sum+=arr[i];
    }
    return round((double)sum/N);
}

int median(int* arr, int N){ // 중앙값
    return arr[N/2];
}

int mode(int* arr, int N) {
    int counts[8001] = {0};
    for(int i=0; i<N; i++)
        counts[arr[i]+4000]++;

    int max_count = 0;
    for(int i=0; i<8001; i++)
        if(counts[i] > max_count) max_count = counts[i];

    int first = 1;
    int mode_val = 0;
    for(int i=0; i<8001; i++) {
        if(counts[i] == max_count) {
            if(first) { 
                mode_val = i-4000; 
                first = 0; 
            } else {
                return i-4000; 
            }
        }
    }
    return mode_val; 
}


int range(int* arr, int N){ // 범위
    return arr[N-1]-arr[0];
}

int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}


int main(){
    int N;
    scanf("%d", &N);
    int *arr = (int*)malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
    printf("%d\n", arithmetic_mean(arr, N));   
    printf("%d\n", median(arr, N));
    printf("%d\n", mode(arr, N));
    printf("%d\n", range(arr, N));
    free(arr);
    return 0;
}