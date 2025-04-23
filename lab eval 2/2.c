#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*first = NULL;

//creation of singly linked list.
void create(int n){
    
    struct node *last,*t;
    
    first = (struct node *) malloc(sizeof(struct node));
    scanf("%d",&first->data);
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++){

        t = (struct node *) malloc(sizeof(struct node));
        scanf("%d",&t->data);
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

//Display function.
void Display(struct node *p){

    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int len(struct node *p){

    int count = 0;
    while(p){
        p = p->next;
        count++;
    }

    return count;
}

//this function is to return the node after reversing the list.
struct node* reverse_k_nodes(struct node* temp, struct node* p) {

    //store temp in a current pointer which moves upto where we have to reverse.
    struct node *prev = NULL, *curr = temp, *next = NULL;
    struct node *stop = p->next; // it points where we have to reverse.

    while (curr != stop) {

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    return prev; // new head of reversed nodes
}

//function to reverse the k nodes..
//firstly check if given length of list is greater than the k group of nodes we have to reverse
void reverseKGroups(int k) {

    if (k <= 1 || !first) return;

    int length = len(first);
    if (length < k) return;

    struct node *temp = first;         // Start of 1st k-group
    struct node *prevGroupTail = NULL; // End of previous reversed group

    while (length >= k) {
        struct node *p = temp; // p will move to end of group

        for (int i = 1; i < k; i++) {
            p = p->next;
        }
        
        //check if p is NULL or not, if null then break the loops.
        if(p == NULL) break;
        

        // Reverse the group..
        //make next group with head p->next.

        struct node * nextGroupHead = p->next;
        
        //get the node after reversing,
        struct node *newHead = reverse_k_nodes(temp, p);
        
        
        if (prevGroupTail)
            prevGroupTail->next = newHead;
        else
            first = newHead; // Update head for the first group

        temp->next = nextGroupHead; // temp is now the tail after reverse
        prevGroupTail = temp;
        temp = nextGroupHead;

        length -= k;   //now decrease the length as the groups are getting reversed.
    }
}

int main(){

    int n;
    scanf("%d",&n);

    create(n);
    Display(first);

    printf("\nEnter nodes: ");
    int k;
    scanf("%d",&k);

    reverseKGroups(k);
    Display(first);

    return 0;
}