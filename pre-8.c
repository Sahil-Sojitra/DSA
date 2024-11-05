#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    /* data */
    int data;
    struct node *next;
};
struct node *head= NULL;
void push(int n){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;

    newnode->next = head;

    head = newnode;
}
void pop(){
    struct node *temp;

    if(head == NULL){
        printf("Stack is empty");
    }
    else{
        printf("The poped element is : %d\n",head->data);
        temp = head;
        head=head->next;
        free(temp);
    }
}
void printList(){
    struct node * temp =  head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    push(10);
    push(20);
    push(30);
    printf("Linked list \n");
    printList();
    pop();
    printf("After the pop, the new linked list : \n");
    printList();
    pop();
    printf("After the pop, the new linked list : \n");
    printList();
    return 0;
}