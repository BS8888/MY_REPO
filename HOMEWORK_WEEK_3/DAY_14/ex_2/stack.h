#include <stdio.h>
#ifndef STACK_H
#define STACK_H 1

typedef struct Node{
    int data;
    struct Node* next;
}N;

typedef struct Stack{
    N* top;
}S;

void initStack(S*);
int isEmpty(S*);
void push(S*, int);
int pop(S*);
void printStack(S*);

#endif