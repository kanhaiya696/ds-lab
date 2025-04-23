
#include<stdio.h>
#include<stdlib.h>

struct node{
    int a;
    struct node*next;
};

struct node*create_node(int data){
    struct node*cnode=(struct node*)malloc(sizeof(cnode));
    cnode->a=data;
    cnode->next=NULL;
    return cnode;
}

void display(struct node*head){
    struct node*ptr=head;
    do{
        printf("%d",ptr->a);
        ptr=ptr->next;
    }while(ptr!=head);
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
    nnode->next=head;
    return head;
}

int main(){
    int n,i;
    struct node*nnode,*head;
    head=NULL;
    int data;
    printf("Enter the number of elements you want to enter");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        head=input(data,head);
    }

    display(head);
  

    return 0;
}