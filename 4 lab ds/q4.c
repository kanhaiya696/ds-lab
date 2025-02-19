// [x] Length of linked list.
// [x] Find 3rd node from end.
// [x] Swap 2 adjacent nodes.
// [ ] Implement Bubble Sort.
// [ ] Assume there are 2 sorted lists, create a third list 
//            from those two such that it is sorted as well.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int getListLength(struct Node *head);
void appendToList(struct Node **head, int value);
void addAtStart(struct Node **head, int value);
void printList(struct Node *head);
struct Node* getNthFromEnd(struct Node* head, int position);
void swapNodeData(struct Node *a, struct Node *b);
void bubbleSortList(struct Node **head);
void mergeSortedLists(struct Node* list1, struct Node* list2, struct Node** mergedList);

int main() {
    struct Node *head = NULL;

    appendToList(&head, 10);
    appendToList(&head, 20);
    appendToList(&head, 30);
    appendToList(&head, 5);
    appendToList(&head, 50);
    appendToList(&head, 1);
    appendToList(&head, 35);

    printf("Original Linked List:\n");
    printList(head);

    printf("Size of Linked List = %d\n", getListLength(head));

    printf("\nAfter swapping 1st and 2nd Node:\n");
    swapNodeData(head, head->next);
    printList(head);

    printf("\nSorting the Linked List...\n");
    bubbleSortList(&head);
    printf("Sorted Linked List:\n");
    printList(head);

    struct Node* A = NULL;
    struct Node* B = NULL;
    struct Node* C = NULL;

    appendToList(&A, 10);
    appendToList(&A, 20);
    appendToList(&A, 30);
    appendToList(&A, 40);

    appendToList(&B, 5);
    appendToList(&B, 8);
    appendToList(&B, 25);
    appendToList(&B, 35);

    printf("\nList 1:\n");
    printList(A);

    printf("\nList 2:\n");
    printList(B);

    mergeSortedLists(A, B, &C);

    printf("\nMerged Sorted List:\n");
    printList(C);

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

void appendToList(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void addAtStart(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* getNthFromEnd(struct Node* head, int position) {
    int length = getListLength(head);
    if (position > length || position <= 0) {
        printf("Invalid position.\n");
        return NULL;
    }

    struct Node* current = head;
    for (int i = 1; i < length - position + 1; i++) {
        current = current->next;
    }

    return current;
}

void swapNodeData(struct Node *a, struct Node *b) {
    if (a == NULL || b == NULL) {
        printf("Invalid nodes for swapping.\n");
        return;
    }
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSortList(struct Node **head) {
    if (*head == NULL) return;
    
    int swapped;
    struct Node *current;
    struct Node *lastSorted = NULL;

    do {
        swapped = 0;
        current = *head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                swapNodeData(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        lastSorted = current;
    } while (swapped);
}

void mergeSortedLists(struct Node* list1, struct Node* list2, struct Node** mergedList) {
    struct Node *p = list1, *q = list2;
    struct Node *mergedHead = NULL, *mergedTail = NULL;

    while (p != NULL && q != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (p->data <= q->data) {
            newNode->data = p->data;
            p = p->next;
        } else {
            newNode->data = q->data;
            q = q->next;
        }
        newNode->next = NULL;

        if (mergedHead == NULL) {
            mergedHead = mergedTail = newNode;
        } else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
    }

    while (p != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = p->data;
        newNode->next = NULL;
        mergedTail->next = newNode;
        mergedTail = newNode;
        p = p->next;
    }

    while (q != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = q->data;
        newNode->next = NULL;
        mergedTail->next = newNode;
        mergedTail = newNode;
        q = q->next;
    }

    *mergedList = mergedHead;
}
