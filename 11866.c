#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node; 

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    Node* head = NULL;
    Node* tail = NULL;
    for(int i=1; i<=N; i++){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head; 
    printf("<");
    Node* prev = tail; 
    while(N--){
        for(int i=0; i<K-1; i++){ 
            prev = head;
            head = head->next;
        }
        printf("%d", head->data);
        if(N != 0) printf(", ");
        prev->next = head->next;
        free(head);
        head = prev->next;
    }
    printf(">\n");
    return 0;
}
