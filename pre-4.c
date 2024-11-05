#include<stdio.h>
#include<string.h>

char nextchar(char str[],int index){
    return str[index];
}

int stack[100];
int top = -1;

int isfull(){
    if(top == 99){
        return 1;
    }
    else{
        return 0 ;
    }
}

int isempty(){
    if(top == -1){
        return 1 ;
    }
    else{
        return 0 ;
    }
}

char push(char n){
    if(isfull()){
        printf("Stack is full\n");
    }
    else{
        top++;
        stack[top] = n;
        return n ;
    }
}

char pop(){
    if(isempty()){
        printf("Stack is empty\n");
    }
    else{
        char temp = stack[top];
        top--;
        return temp ;
    }
}
int main(){
    char str[] = "abcbaa";
    int i=0, len = strlen(str);
    stack[++top]='c';

    char next = nextchar(str,i++);
    while(next != 'c'){
        if(next == " "){
            printf("invalid string");
            break;
    }
    else{
        push(next);
        printf("Enterrd character is : %c\n",next);
        next = nextchar(str,i++);
    }
}

while(stack[top]!='c'){
    next=nextchar(str,i++);
    char n = pop();
    printf("retrived char is : %c\n",n);

    if(next != n){
        printf("invalid string");
        break;
    }
}

next= nextchar(str,i++);
    if(next == ' '){
        printf("valid string");
    }
    else{
        printf(" string invalid check your  input string again");
    }

return 0;
}
