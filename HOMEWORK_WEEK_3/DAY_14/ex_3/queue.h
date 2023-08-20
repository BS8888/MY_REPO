#include <stdio.h>
#include <stdlib.h>
#ifndef QUEUE_H
#define QUEUE_H 1

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

#endif