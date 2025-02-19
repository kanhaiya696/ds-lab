#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void append(struct Node **head, int value);
void printList(struct Node *head);
struct Node* mergeSort(struct Node *head);
struct Node* merge(struct Node *left, struct Node *right);
struct Node* findMiddle(struct Node *head);

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

    head = mergeSort(head);

    printf("Sorted List (Merge Sort):\n");
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

struct Node* merge(struct Node *left, struct Node *right) {
    struct Node *result = NULL;

    if (!left) return right;
    if (!right) return left;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

struct Node* findMiddle(struct Node *head) {
    if (!head) return NULL;

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct Node* mergeSort(struct Node *head) {

    if (!head || !head->next) return head;

    struct Node *middle = findMiddle(head);
    struct Node *left = head;
    struct Node *right = middle->next;
    middle->next = NULL;  

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}