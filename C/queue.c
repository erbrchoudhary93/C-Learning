
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void init_queue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

bool enqueue(Queue *q, int value)
{
    Node *new_node = malloc(sizeof *new_node);

    if (new_node == NULL) {
        return false;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    return true;
}

bool dequeue(Queue *q, int *removed_value)
{
    if (q->front == NULL) {
        return false;
    }

    Node *temp = q->front;
    *removed_value = temp->data;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return true;
}

void display(const Queue *q)
{
    Node *current = q->front;

    printf("FRONT -> ");

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void free_queue(Queue *q)
{
    int value;

    while (dequeue(q, &value)) {
        // dequeue frees each node
    }
}

int main(void)
{
    Queue q;
    int value;

    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    if (dequeue(&q, &value)) {
        printf("Removed: %d\n", value);
    }

    enqueue(&q, 40);
    display(&q);

    free_queue(&q);
    return 0;
}
