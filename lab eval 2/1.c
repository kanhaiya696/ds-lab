#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;
} *first = NULL,*second = NULL, *third = NULL;
 
void create(struct node **p,int n){ 

    struct node *last, *t;
    *p = (struct node*) malloc (sizeof(struct node));

    (*p)->next = NULL;
    scanf("%d",&(*p)->data);
    last = *p;   
    for(int i=1;i<n;i++){

        t = (struct node*) malloc (sizeof(struct node));
        scanf("%d",&t->data);
        t->next = NULL;  
        last->next = t;  
        last = t;   
    }
}


void Display(struct node *p){

    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}


void add_numbers(struct node *p,struct node *q){
    
    struct node * last, *t;
    if(p == NULL){
        third = q;
        return;
    }

    if(q== NULL){
        third = q;
        return;
    }

    while(p && q){

        if(third == NULL){
           third = (struct node *) malloc(sizeof(struct node));
           third->data = p->data + q->data;
           last = third;
           last->next = NULL;
        }
        else{
         t = (struct node *) malloc(sizeof(struct node));
         t->data = p->data + q->data;
         t->next = NULL;
         last->next = t;
         last = t;
        }

        p = p->next;
        q = q->next;
    }
}

int main(){

    int n;
    scanf("%d",&n);

    create(&first,n);

    int m;
    scanf("%d",&m);

    create(&second,m);
    
    printf("After Addition:\n");
    add_numbers(first,second);
    Display(third);

    return 0;
}