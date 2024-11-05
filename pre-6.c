#include<stdio.h>

int queue[5];
int N=5;
int front =0;
int rear =0;

void enqueue(int n){
    if (rear== N){
        rear=1;
    }
    else{
        rear++;
    }
    if (front == rear)
    {
        printf("Overflow\n");
        if (rear == 1)
        {
            rear = N; 
        }
        else
        {
            rear = rear - 1;
        }
        return;
    }
    queue[rear - 1] = n;
    printf("Inserted element: %d\n", n);

    if (front == 0)
    {
        front = 1; 
    }
}

void dequeue(){
    if(front==0){
        printf("Underflow\n");
        return 0 ;
    }
    int n=queue[front-1];
    printf("Deleted element is : %d\n",n);
    
    if(front==rear){
        front =0;
        rear=0;
        return printf("%d\n",n);
    }
    if(front==N){
        front=1;
    }
    else{
        front++;
    }
}

void display()
{
    if (front == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i = front - 1; // Adjust for 0-based index
    while (i != rear - 1)
    {
        printf("| %d |", queue[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", queue[i]);
}

int main(){
    enqueue(2);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    dequeue();
    dequeue();
    display();
}

