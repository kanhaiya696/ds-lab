#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


void splitList(struct Node* head, struct Node** front, struct Node** back) {
    struct Node* slow = head;
    struct Node* fast = head->next;
    

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *front = head;
    *back = slow->next;
    slow->next = NULL;  
}

struct Node* merge(struct Node* front, struct Node* back) {
    // Base cases
    if (front == NULL) return back;
    if (back == NULL) return front;

    struct Node* result = NULL;

   
    if (front->data <= back->data) {
        result = front;
        result->next = merge(front->next, back);
    } else {
        result = back;
        result->next = merge(front, back->next);
    }
    return result;
}

struct Node* mergeSort(struct Node* head) {
   
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* front = NULL;
    struct Node* back = NULL;


    splitList(head, &front, &back);

    
    front = mergeSort(front);
    back = mergeSort(back);

    return merge(front, back);
}

int main() {
    struct Node* head = NULL;

    head = createNode(38);
    head->next = createNode(27);
    head->next->next = createNode(43);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(9);
    head->next->next->next->next->next = createNode(82);
    head->next->next->next->next->next->next = createNode(10);

    printf("Original Linked List: ");
    printList(head);

  
    head = mergeSort(head);

    printf("Sorted Linked List: ");
    printList(head);

    return 0;
}