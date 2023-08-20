#include <stdlib.h>
#include "stack.h"

void initStack(S* stack){
    stack->top = NULL;
}

int isEmpty(S* stack){
    return (stack->top == NULL);
}

void push(S* stack, int data){
    N* newNode = malloc(sizeof(N));
    if(newNode == NULL) exit(EXIT_FAILURE);
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(S* stack){
    if (isEmpty(stack)) exit(EXIT_FAILURE);
    int data = stack->top->data;
    N* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void printStack(S* stack){
    N* current = stack->top;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}