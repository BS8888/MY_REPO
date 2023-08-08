#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void print(Node* cll){
    if(cll == NULL){
        printf("Empty list.\n");
        return;
    }

    Node* current = cll;
    do{
        printf("%d ", current->data);
        current = current->next;
    }while(current != cll);
    printf("\n");
}

int main() {
    int N;
    printf("Enter number of elems: ");
    scanf("%d", &N);
    if(N<=0) return 1;

    Node* head = NULL;
    Node* prev = NULL;
    
    for(int i = 0; i < N; i++){
        Node* newNode = malloc(sizeof(Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        
        if(prev != NULL) prev->next = newNode;
        else head = newNode;
        
        prev = newNode;
    }
    if(prev != NULL) prev->next = head;

    printf("Cyclic linked list: ");
    print(head);

    Node* current = head;
    do{
        struct Node* next = current->next;
        free(current);
        current = next;
    }while(current != head);

    return 0;
}