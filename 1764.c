#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[31];
} human;

int compare_str(const void *a, const void *b) {
    const human *ha = (const human *)a;
    const human *hb = (const human *)b;
    return strcmp(ha->name, hb->name);
}

int binary_search_str(human* arr, int size, const char *target){
    int left = 0, right = size - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid].name, target);
        if(cmp == 0){
            return 1;
        } else if(cmp > 0){
            right = mid - 1;
        } else {
            left = mid + 1; 
        }
    }
    return 0; 
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    human* humans = malloc(sizeof(human) * n);
    for(int i=0; i<n; i++){
        scanf("%s", humans[i].name);
    }

    qsort(humans, n, sizeof(human), compare_str);

    human* buffer = malloc(sizeof(human) * (n < m ? n : m)); 
    int count = 0;  // 교집합 개수

    for(int i=0; i<m; i++){
        char target[31];
        scanf("%s", target);
        if(binary_search_str(humans, n, target)) {
            strcpy(buffer[count++].name, target);
        }
    }

    qsort(buffer, count, sizeof(human), compare_str);

    printf("%d\n", count);   
    for(int i=0; i<count; i++){
        printf("%s\n", buffer[i].name);
    }

    free(humans);
    free(buffer);
    return 0;
}
