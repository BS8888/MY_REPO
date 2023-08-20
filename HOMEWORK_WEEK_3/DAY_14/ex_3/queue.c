//#include "queue.h"
#include "stack_queue.h"
void initQueue(Q* queue, int capacity){
    queue->data = malloc(sizeof(int) * capacity);
    if(queue->data == NULL) exit(EXIT_FAILURE);
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
}

int isQueueEmpty(Q* queue){
    return (queue->size == 0);
}

int isQueueFull(Q* queue){
    return (queue->size == queue->capacity);
}

void enqueue(Q* queue, int value){
    if(isQueueFull(queue)){
        printf("Queue is full\n");
        return;
    }
    if(queue->rear == -1) queue->front = queue->rear = 0;
    else queue->rear = (queue->rear + 1) % queue->capacity;

    queue->data[queue->rear] = value;
    queue->size++;
}

int dequeue(Q* queue){
    if(isQueueEmpty(queue)) exit(EXIT_FAILURE);
    int value = queue->data[queue->front];
    if(queue->front == queue->rear) queue->front = queue->rear = -1;
    else queue->front = (queue->front + 1) % queue->capacity;
    
    queue->size--;
    return value;
}

void freeQueue(Q* queue){
    free(queue->data);
}
