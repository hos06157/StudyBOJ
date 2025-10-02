#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char ID[21];
    char PW[21];
}User;

int compare_str(const void *a, const void *b) {
    const User *ua = (const User *)a;
    const User *ub = (const User *)b;
    return strcmp(ua->ID, ub->ID);
}

int binary_search_str(User* arr, int size, const char *target){
    int left = 0, right = size - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid].ID, target);  
        if(cmp == 0){
            return mid;  
        } else if(cmp > 0){
            right = mid - 1;  
        } else {
            left = mid + 1;   
        }
    }
    return -1;  
}

int main(){
    int N, M;

    scanf("%d %d", &N, &M);
    User* user = (User*)malloc(sizeof(User)*N);
    for(int i=0; i<N;i++){
        scanf("%s %s", user[i].ID, user[i].PW);
    }
    qsort(user, N, sizeof(User), compare_str);
    
    for(int i=0; i<M; i++){
        char buffer[21];
        scanf("%s", buffer);
        int idx = binary_search_str(user, N, buffer);
        if (idx != -1) {
            printf("%s\n", user[idx].PW);
        }
    }
    return 0;
}