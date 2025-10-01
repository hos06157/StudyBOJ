#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[21];
    int number;
} Pokemon;

int cmp(const void* a, const void* b){
    return strcmp(((Pokemon*)a)->name, ((Pokemon*)b)->name);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    Pokemon* pokemons = malloc(sizeof(Pokemon) * a);
    for(int i=0; i<a; i++){
        scanf("%s", pokemons[i].name);
        pokemons[i].number = i + 1;
    }
    Pokemon* sorted = malloc(sizeof(Pokemon) * a);
    memcpy(sorted, pokemons, sizeof(Pokemon) * a);
    qsort(sorted, a, sizeof(Pokemon), cmp);

    char buffer[21];
    for(int i=0; i<b; i++){
        scanf("%s", buffer);
        if(buffer[0] >= '0' && buffer[0] <= '9'){
            int num = atoi(buffer);
            printf("%s\n", pokemons[num - 1].name);
        } else {
            int left = 0, right = a - 1;
            while(left <= right){
                int mid = (left + right) / 2;
                int res = strcmp(buffer, sorted[mid].name);
                if(res == 0){
                    printf("%d\n", sorted[mid].number);
                    break;
                } else if(res < 0){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
    }
    free(pokemons);
    free(sorted);
    return 0;
}
