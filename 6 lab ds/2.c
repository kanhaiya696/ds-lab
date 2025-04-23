#include<stdio.h>
#include<stdlib.h>
struct node{
    int a;
    struct node*next;
};

struct node* create_node(int data){
    struct node*cnode;
    cnode=(struct node*)malloc(sizeof(struct node));
    cnode->a=data;
    cnode->next=NULL;
    return cnode;
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
    return head;
}

void display(struct node*ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->a);
        ptr=ptr->next;
    }
}

void even_odd(struct node*head){
    struct node*temp=head,*head1,*head2;
   while((temp->next)!=0){
    if(temp->a%2==0){
        head1=input(temp->a,head1);
        display(head1);
    }
    else{
        head2=input(temp->a,head2);
        display(head2);
    }
    temp=temp->next;
   }
    
}
int main(){
    struct node*head,*first,*second,*third,*fourth,*fifth,*sixth;
    head=(struct node*)malloc(sizeof(struct node*));
    first=(struct node*)malloc(sizeof(struct node*));
    second=(struct node*)malloc(sizeof(struct node*));
    third=(struct node*)malloc(sizeof(struct node*));
    fourth=(struct node*)malloc(sizeof(struct node*));
    fifth=(struct node*)malloc(sizeof(struct node*));
    sixth=(struct node*)malloc(sizeof(struct node*));

    head->a=10;
    head->next=first; 
    first->a=5;
    first->next=second;
    second->a=20;
    second->next=third;
    third->a=21;
    third->next=fourth;
    fourth->a=12;
    fourth->next=fifth;
    fifth->a=14;
    fifth->next=sixth;
    sixth->a=7;
    sixth->next=NULL;


    even_odd(head);
    return 0;
}