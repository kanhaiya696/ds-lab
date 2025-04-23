
//the question was to implement linked list which is constructed on the basis of two stacks,
//both stacks are independent and they both contain the values of list.

//as it was not specified so user can push in any stack to implement linked list.
//else using rand() % 2 which give random value  0 and 1 randomly and then pushing element in either of the stack on basis of 0 1.

#include <stdio.h>
#include <stdlib.h>

// Node structure for creation of linked list using stack.
struct Node {
    int data;
    struct Node* next;
};

// Stack pointers , make two pointers as they both are independent,
struct Node* top1 = NULL;
struct Node* top2 = NULL;

// Push to stack
void push(struct Node** top, int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;

    *top = newNode;
}

// Pop from stack
int pop(struct Node** top) {

    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = temp->next;

    free(temp);

    return popped;
}

// Display stack individually.
void display(struct Node* top, int stackNum) {
    
    printf("Stack %d: ", stackNum);
    
    while (top) {
        printf("%d ", top->data);
        top = top->next;
    }
    
    printf("\n");
}

// Display linked list which is constructed of both stacks
void displayCombinedList(struct Node* top1, struct Node* top2) {
    printf("Linked List:\n");

    struct Node* temp = top1;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    temp = top2;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {

    // Pushing elements to both stacks
    push(&top1, 10);
    push(&top1, 20);
    push(&top1, 30);

    push(&top2, 100);
    push(&top2, 200);
    push(&top2, 300);


    // Display both stacks
    display(top1, 1);
    display(top2, 2);


    // Pop from both stacks
    printf("Popped from Stack 1: %d\n", pop(&top1));
    printf("Popped from Stack 2: %d\n", pop(&top2));


    // Display after popping
    display(top1, 1);
    display(top2, 2);
    
    printf("\n");
    displayCombinedList(top1,top2);
    return 0;
}