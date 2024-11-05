#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>


int stack[100];
int top=-1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top==99){
        return 1;
    }
    else{
        return 0;
    }    
}

int push (int n){
    if(isFull()){
        printf("Stack is full\n");
    }
    else{
        top++;
        stack[top]=n;
        printf("The inserted data is : %d\n",n);
    }
}

int pop(int n){
    if(isEmpty()){
        printf("Stack is Empty\n");
    }
    else{
        int temp=stack[top];
        top--;
        printf("The deleted data is : %d\n",temp);
    }
}

int peep(int n){
    if(isEmpty()){
        printf("Stack is Empty\n");
    }
    else{
        printf("The top element is : %d\n",stack[top]);
    }
}

int change(int n){
    if(isEmpty()){
        printf("Stack is Empty\n");
    }
    else{
        stack[top]=n;
        printf("the modified top of the element is : %d",stack[top]);
    }
}
int main(){

    push(3);
    push(5);
    push(7);
    push(9);
    push(11);
    push(13);
    push(15);
    pop(3);
    peep(13);
    change(90);

    return 0;
}