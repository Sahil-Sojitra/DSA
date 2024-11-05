#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int N=500;
int queue[500];
int front=-1;
int rear=-1;


void enqueue(int n){
    if(rear >= N){
        printf("Queue is full");
    }
    else if(front == -1&&rear==-1){
        front = rear = 0;
        queue[rear] = n;
        printf("The enetered element is : %d\n",n);
    }
    else{
        rear++;
        queue[rear] = n;
        printf("The enetered element is : %d\n", n);
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }
    else if(front == rear){
        front==rear==0;
        printf("The deleted element is : %d\n", queue[front]);
    }
    else {
        printf("The deleted element is : %d\n", queue[front]);
        front++;
    }
}

void display(){
    int i;
    printf("the queue elements are : ");
    for (i=front; i<=rear; i++){
        printf("%d ",queue[i]); 
    }
} 
int main(){
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    display();
    return 0;
}