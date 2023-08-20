//#include "stack.h"
#include "stack_queue.h"
void initStack(S* stack, int capacity){
    stack->data = malloc(sizeof(int) * capacity);
    if(stack->data == NULL) exit(EXIT_FAILURE);
    stack->top = -1;
    stack->capacity = capacity;
}

int isStackEmpty(S* stack){
    return (stack->top == -1);
}

int isStackFull(S* stack){
    return (stack->top == stack->capacity - 1);
}

void push(S* stack, int value){
    if(isStackFull(stack)){
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(S* stack){
    if(isStackEmpty(stack)) exit(EXIT_FAILURE);
    return stack->data[stack->top--];
}

void freeStack(S* stack){
    free(stack->data);
}
