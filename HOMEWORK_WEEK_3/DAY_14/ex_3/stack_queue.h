#include <stdio.h>
#include <stdlib.h>
#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H 1

typedef struct Queue{
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
}Q;

void initQueue(Q*, int);
int isQueueEmpty(Q*);
int isQueueFull(Q*);
void enqueue(Q*, int);
int dequeue(Q*);
void freeQueue(Q*);

typedef struct Stack{
    int* data;
    int top;
    int capacity;
}S;

void initStack(S*, int);
int isStackEmpty(S*);
int isStackFull(S*);
void push(S*, int);
int pop(S*);
void freeStack(S*);

#endif



