#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 5

typedef struct {
    int data[CAPACITY];
    int front;
    int rear;
    int count;
} CircularQueue;

void init_queue(CircularQueue *q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

bool enqueue(CircularQueue *q, int value) {
    if (q->count == CAPACITY) {
        return false;  // Queue full
    }

    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % CAPACITY;
    q->count++;

    return true;
}

bool dequeue(CircularQueue *q, int *value) {
    if (q->count == 0) {
        return false;  // Queue empty
    }

    *value = q->data[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->count--;

    return true;
}

int main(void) {
    CircularQueue q;
    int removed;

    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    dequeue(&q, &removed);
    printf("Removed: %d\n", removed);

    enqueue(&q, 40);

    printf("Front index: %d\n", q.front);
    printf("Rear index: %d\n", q.rear);
    printf("Count: %d\n", q.count);

    return 0;
}