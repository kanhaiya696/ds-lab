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

struct node*deletion(int m,int n, struct node*head){
    
    struct node*temp=head;
    if(m==1){
        head=temp->next;
        temp->next=NULL;
        free(temp);
    }
    else if(m>1 && m<n){
        for(int i=1;i<m-1;i++){
            temp=temp->next;
        }
        struct node*temp2=temp->next;
        temp->next=temp2->next;
        temp2->next->prev=temp;
        free(temp2);
        }
        
        else if(m==n){
            struct node*prevnode;
            while(temp->next!=NULL){
                prevnode=temp;
                temp=temp->next;
            }
            prevnode->next=NULL;
            free(temp);

        }
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
    int m;
    printf("Enter the position at which you want to delete element:");
    scanf("%d",&m);

    head=deletion(m,n,head);
    display(head);


}