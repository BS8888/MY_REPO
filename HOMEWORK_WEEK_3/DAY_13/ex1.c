#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}N;

typedef struct Deque{
    N* front;
    N* rear;
}D;

void initDeque(D* deque){
    deque->front = NULL;
    deque->rear = NULL;
}

int isEmpty(D* deque){
    return deque->front == NULL;
}

void addToFront(D* deque, int data){
    N* newNode = malloc(sizeof(N));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;

    if(isEmpty(deque)){
        deque->front = newNode;
        deque->rear = newNode;
    } 
    else{
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void addToRear(D* deque, int data){
    N* newNode = malloc(sizeof(N));
    newNode->data = data;
    newNode->prev = deque->rear;
    newNode->next = NULL;

    if(isEmpty(deque)){
        deque->front = newNode;
        deque->rear = newNode;
    } 
    else{
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int removeFromFront(D* deque){
    if(isEmpty(deque)) printf("Deque is empty.\n");
        
    int data = deque->front->data;
    N* temp = deque->front;

    if(deque->front == deque->rear){
        deque->front = NULL;
        deque->rear = NULL;
    } 
    else{
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    free(temp);
    return data;
}

int removeFromRear(D* deque){
    if (isEmpty(deque)) printf("Deque is empty.\n");
        
    int data = deque->rear->data;
    N* temp = deque->rear;

    if(deque->front == deque->rear){
        deque->front = NULL;
        deque->rear = NULL;
    } 
    else{
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    free(temp);
    return data;
}

void printDeque(D* deque){
    N* current = deque->front;
    printf("Deque: ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    D myDeque;
    initDeque(&myDeque);

    addToFront(&myDeque, 2);
    addToFront(&myDeque, 1);
    addToRear(&myDeque, 3);
    addToRear(&myDeque, 4);

    printDeque(&myDeque);

    int frontElement = removeFromFront(&myDeque);
    int rearElement = removeFromRear(&myDeque);

    printf("Removed front element: %d\n", frontElement);
    printf("Removed rear element: %d\n", rearElement);

    printDeque(&myDeque);

    return 0;
}