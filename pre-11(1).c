#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int info;
    struct node *link;
};
struct node *first = NULL, *last = NULL;
struct node *avail = NULL;

void push_avail(struct node *node)
{
    node->link = avail;
    avail = node;
}

void insert_first(struct node **first, struct node **last, int value){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info=value;

    if(*first == NULL){
        newnode->link=newnode;
        *first=*last=newnode;
    }

    else{
        newnode->link=*first;
        (*last)->link=newnode;
        *first=newnode;
    }
}

void insert_last(struct node **first , struct node **last , int value){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->info = value;

    if (*first == NULL)
    {
        newnode->link = newnode;
        *first = *last = newnode;
    }

    else {
        newnode->link = *first;
        (*last)->link = newnode;
        *last = newnode;
    }
}

void insert_ord(struct node **first, struct node **last, int value){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info=value;
    
    if(*first == NULL){
        newnode->link= newnode;
        *first=*last=newnode;
        return;
    }

    if(newnode->info <= (*first)->info){
        newnode->link=*first;
        (*last)->info = newnode;
        *first = newnode;
        return;
    } 

    struct node *save = *first;

    while(save != (*last) && newnode->info>= (save->link)->info){
        save = save->link;
    }

        newnode->link = save->link;
        save->link = newnode;

        if(save==(*last)){
            *last = newnode;
        }
}

void delete(struct node **first, struct node **last, int value){
    if(*first==NULL){
        printf("the linked list if empty.\n");
    }

    struct node *save ;
    save=*first;
    struct node *pred ;
    pred = NULL;

    while(save->info!=value && save != *last){
        pred = save;
        save = save->link;
    }

    if(save->info!=value){
        printf("Node not Found.");
    }

    if(value==*first){
        *first=(*first)->link;
        (*last)->link = *first;
    }
    else{
        pred->link = save->link;
        if(value==*last){
            *last = pred;
        }
    }
    free(value);
}

    void display(struct node *first)
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = first;
    do
    {
        printf("%d ", temp->info);
        temp = temp->link;
    } while (temp != first); 
    printf("\n");
}

void avail_stack(int n){
    int i;
    for (i = 0; i < n; i++)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        push_avail(newnode);
    }
}
struct node *head = NULL;
int main(){
    avail_stack(5);
    insert_first(&first,&last,20);
    insert_first(&first,&last,10);
    insert_first(&first,&last,5);
    insert_last(&first,&last,50);
    insert_last(&first, &last, 1);
    insert_ord(&first,&last,15);
    delete(&first, &last,15);
    delete (&first, &last,50);
    printf("The circular linked list is: ");
    display(first);
    return 0;
}