#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int my_round(double x) {
    return (int)(x + 0.5);
}

int main(){
    int n;
    scanf("%d", &n);
    if(n==0){
        printf("0\n");
        return 0;
    }
    int* arr = (int*)malloc(n * sizeof(int));
    int TrimmedMean = my_round(n*0.15);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    int sum = 0;
    for(int i=TrimmedMean; i<n-TrimmedMean; i++){
        sum+=arr[i];
    }
    printf("%d\n", my_round((double)sum / (n - 2 * TrimmedMean)));
    free(arr);
    return 0;
}