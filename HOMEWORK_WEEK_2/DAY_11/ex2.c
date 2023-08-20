#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STACK_SIZE 100

typedef struct Stack{
    int data[STACK_SIZE];
    int top;
}S;

void initStack(S *stack){
    stack->top = -1;
}

void push(S *stack, int value){
    if(stack->top < STACK_SIZE - 1) stack->data[++stack->top] = value;
    else printf("Stack overflow\n");
}

int pop(S *stack){
    if (stack->top >= 0) return stack->data[stack->top--];
    else printf("Stack underflow\n");
    exit(EXIT_FAILURE);
}

int main(){
    S stack;
    initStack(&stack);

    char input[100];
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while(token != NULL){
        if(isdigit(token[0])) push(&stack, atoi(token));
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*'){
            int op2 = pop(&stack);
            int op1 = pop(&stack);
            int result;

            if (token[0] == '+') result = op1 + op2;
            else if (token[0] == '-') result = op1 - op2;
            else if (token[0] == '*') result = op1 * op2;
    
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }
    int finalResult = pop(&stack);
    printf("%d\n", finalResult);

    return 0;
}
//12 + 3 * 5 -
//1 2 + 3 * 5 -