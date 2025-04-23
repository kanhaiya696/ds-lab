// Perform enqueue and dequeue on circular queue(made using array).
 
#include <stdio.h>
#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

void enq(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("q is FULL! Cannot enq %d\n", value);
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;
    q[rear] = value;
    printf("Enqd: %d\n", value);
}

void deq() {
    if (front == -1) {
        printf("q is EMPTY! Cannot deq.\n");
        return;
    }
    printf("Deqd: %d\n", q[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void disp() {
    if (front == -1) {
        printf("q is EMPTY.\n");
        return;
    }
    printf("q contents: ");
    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enq(10);
    enq(20);
    enq(30);
    enq(40);
    enq(50);
    enq(60);

    disp();

    deq();
    deq();

    enq(60);
    enq(70);

    disp();

    return 0;
}

/*
Enqueued: 10
Enqueued: 20
Enqueued: 30
Enqueued: 40
Enqueued: 50
Queue is FULL! Cannot enqueue 60
Queue contents: 10 20 30 40 50
Dequeued: 10
Dequeued: 20
Enqueued: 60
Enqueued: 70
Queue contents: 30 40 50 60 70
*/