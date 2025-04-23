// Program to Implement a Dynamic Queue using Linked List
 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int value) {
    Node* nNode = (Node*)malloc(sizeof(Node));
    nNode->data = value;
    nNode->next = NULL;

    if (q->rear == NULL)
        q->front = q->rear = nNode;
    else {
        q->rear->next = nNode;
        q->rear = nNode;
    }

    printf("Enqueued: %d\n", value);
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return;
    }

    Node* temp = q->front;
    printf("Dequeued: %d\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue contents: ");
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 5);
    enqueue(q, 15);
    enqueue(q, 25);

    display(q);

    dequeue(q);
    enqueue(q, 35);

    display(q);

    return 0;
}

/*
Enqueued: 5
Enqueued: 15
Enqueued: 25

Queue contents: 5 15 25 

Dequeued: 5
Enqueued: 35

Queue contents: 15 25 35 
*/