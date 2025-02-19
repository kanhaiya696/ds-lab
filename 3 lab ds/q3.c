// [x] 1. Write a program to create a linked list.
// [x] 2. Traverse the linked list and print content of every struct Node.
// [x] 3. Create 2 linked lists having size 'n' & 'm' and add m respectively; derive 3rd list by concatenating these 2 lists.
// [x] 4. Insert a struct Node in the list at beginning, at end, at specific location.
// [x?] 5. Delete a struct Node in the list at beginning, at end, at specific location.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int getListLength(struct Node *head);
void printList(struct Node *head);
struct Node *mergeLists(struct Node *list1, struct Node *list2);
void addAtStart(struct Node **head, int value);
void addAtEnd(struct Node **head, int value);
void insertAtPosition(struct Node **head, int value, int position);
void removeNode(struct Node **head, int value);
void removeNodeAtPosition(struct Node **head, int position);

int main() {
    struct Node *head = NULL;

    printf("Creating Linked List...\n");
    for (int i = 1; i <= 10; i++) {
        insertAtPosition(&head, i * 10, i);
    }
    printList(head);

    printf("\n\n");

    removeNode(&head, 40);
    removeNode(&head, 90);
    removeNode(&head, 20);
    printList(head);

    printf("\n");

    addAtEnd(&head, 120);
    printList(head);

    printf("\n\n");

    struct Node *list1 = NULL;
    for (int i = 1; i <= 4; i++) {
        insertAtPosition(&list1, i * 4, i);
    }
    printList(list1);
    printf("\n");

    struct Node *list2 = NULL;
    for (int i = 1; i <= 3; i++) {
        insertAtPosition(&list2, i * 7, i);
    }
    printList(list2);
    printf("\n");

    struct Node *mergedList = mergeLists(list1, list2);
    printList(mergedList);

    return 0;
}

int getListLength(struct Node *head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

void printList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
struct Node *mergeLists(struct Node *list1, struct Node *list2) {
    struct Node *merged = NULL;

    while (list1 != NULL) {
        addAtEnd(&merged, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        addAtEnd(&merged, list2->data);
        list2 = list2->next;
    }

    return merged;
}

void addAtStart(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = *head;
    
    newNode->data = value;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void insertAtPosition(struct Node **head, int value, int position) {
    if (position < 1 || position > getListLength(*head) + 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        addAtStart(head, value);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node *current = *head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void removeNode(struct Node **head, int value) {
    struct Node *current = *head;
    struct Node *previous = NULL;

    if (current != NULL && current->data == value) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    previous->next = current->next;
    free(current);
}

void removeNodeAtPosition(struct Node **head, int position) {
    if (*head == NULL || position < 1 || position > getListLength(*head)) {
        printf("Invalid position\n");
        return;
    }

    struct Node *current = *head;
    if (position == 1) {
        *head = current->next;
        free(current);
        return;
    }

    struct Node *previous = NULL;
    for (int i = 1; i < position; i++) {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    free(current);
}
