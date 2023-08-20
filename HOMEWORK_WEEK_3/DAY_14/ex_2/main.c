#include "stack.h"

int main() {
    S stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack after pushes: ");
    printStack(&stack);

    printf("Popped element: %d\n", pop(&stack));

    printf("Stack after pop: ");
    printStack(&stack);

    return 0;
}