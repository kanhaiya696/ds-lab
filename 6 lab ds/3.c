#include<stdio.h>
#include<stdlib.h>

struct node{
    int a;
    struct node*next;
    struct node*prev;
};

struct node*create_node(int data){
    struct node*cnode=(struct node*)malloc(sizeof(struct node*));
    cnode->a=data;
    cnode->next=NULL;
    cnode->prev=NULL;
    return cnode;
}

void display(struct node*head){
    while(head!=NULL){
        printf("%d\n",head->a);
        head=head->next;
    }
}

void display_reverse(struct node*head){
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%d\n",temp->a);
        temp=temp->prev;
    }
}

struct node*input(int data,struct node*head){
    struct node*nnode=create_node(data);
    if(head==NULL){
        head=nnode;
        return head;
    }
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nnode;
    nnode->prev=temp;
    return head;
}

int main(){
    int n;
    struct node*nnode,*head;
    head=NULL;
    int data;
    printf("Enter the number of elements you want to enter");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        head=input(data,head);
    }
    printf("Doubly Linked list in forward direction:\n");
    display(head);
    printf("Doubly linked list in backward direction:\n");
    display_reverse(head);
}