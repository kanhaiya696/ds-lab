#include<stdio.h>
#include<stdlib.h>
struct node{
    int a;
    struct node*next;
};

int length(struct node*ptr){
    int i=1;
    while(ptr->next!=NULL){
        i++;
        ptr=ptr->next;
    }
    return i;
}
int main(){
    struct node*head,*first,*second,*third;
    head=(struct node*)malloc(sizeof(struct node*));
    first=(struct node*)malloc(sizeof(struct node*));
    second=(struct node*)malloc(sizeof(struct node*));
    third=(struct node*)malloc(sizeof(struct node*));


    head->a=7;
    head->next=first; 
    first->a=8;
    first->next=second;
    second->a=9;
    second->next=third;
    third->a=10;
    third->next=NULL;

    printf("The length of linked list is %d",length(head));

}