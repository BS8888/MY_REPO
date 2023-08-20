#include <stdio.h>
#include <stdlib.h>
#ifndef STACK_H
#define STACK_H 1

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



