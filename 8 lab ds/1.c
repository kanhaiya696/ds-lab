// Queue Ops
 
#include <stdio.h>
#define SIZE 5

int front = -1, rear = -1;
int q[SIZE];

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("\nQueue is FULL! Cannot insert %d\n", value);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        q[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("\nQueue is EMPTY! Cannot dequeue.\n");
    } else {
        printf("Dequeued: %d\n", q[front]);
        if (front == rear) {
            // Queue has only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void disp() {
    if (front == -1) {
        printf("\nQueue is EMPTY.\n");
    } else {
        printf("\nQueue contents:\n");
        int i = front;
        while (1) {
            printf("%d ", q[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);
    enqueue(30);

    dequeue();
    dequeue();

    enqueue(35);
    enqueue(40);
    enqueue(45);

    disp();

    return 0;
}

/*
Enqueued: 5
Enqueued: 10
Enqueued: 15
Enqueued: 20
Enqueued: 25
Queue is FULL! Cannot insert 30
Dequeued: 5
Dequeued: 10
Enqueued: 35
Enqueued: 40
Queue is FULL! Cannot insert 45

Queue contents:
15 20 25 35 40
*/