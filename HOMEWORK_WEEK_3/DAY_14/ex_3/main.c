// #include "stack.h"
// #include "queue.h"
#include "stack_queue.h"
int main(){
    S stack;
    initStack(&stack, 5);
    Q queue;
    initQueue(&queue, 5);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Stack elements: ");
    while(!isStackEmpty(&stack)) printf("%d ", pop(&stack));
    
    printf("\n");

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    printf("Queue elements: ");
    while(!isQueueEmpty(&queue)) printf("%d ", dequeue(&queue));
    
    printf("\n");

    freeStack(&stack);
    freeQueue(&queue);

    return 0;
}
