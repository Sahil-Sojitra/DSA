#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int n){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;
    
    if(front == NULL & rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next =newnode;
        rear = newnode;
    }
}

void dequeue(){
    struct node *temp = front;
    printf("%d\n",front->data);
    front = front->next;
    free(temp);
}

void display(){
    struct node* temp = front;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
    return 0;
}
