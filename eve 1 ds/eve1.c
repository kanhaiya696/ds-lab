#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void append(struct Node **head, int value);
void printList(struct Node *head);
void sessionSort(struct Node **head);

int main() {
    struct Node *head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 5);
    append(&head, 50);
    append(&head, 1);
    append(&head, 35);

    printf("Original List:\n");
    printList(head);

    sessionSort(&head);

    printf("Sorted List (Min-Max Sort):\n");
    printList(head);

    return 0;
}

void append(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (!*head) {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next) current = current->next;
    current->next = newNode;
}

void printList(struct Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sessionSort(struct Node **head) {
    if (!*head) return;

    struct Node *start = *head, *end = NULL;

    while (start != end) {
        struct Node *minNode = start, *maxNode = start;
        struct Node *current = start;

        while (current) {
            if (current->data < minNode->data) minNode = current;
            if (current->data > maxNode->data) maxNode = current;
            current = current->next;
        }

        if (minNode != start) {
            int temp = start->data;
            start->data = minNode->data;
            minNode->data = temp;
        }

        if (maxNode == start) maxNode = minNode;

        if (maxNode != end) {
            int temp = end->data;
            end->data = maxNode->data;
            maxNode->data = temp;
        }

        start = start->next;
        end = maxNode;
    }
}
