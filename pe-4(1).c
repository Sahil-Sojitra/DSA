#include<stdio.h>
#include<string.h>

int G_rank(char n){
    if(n=='('){
        return 0;
    }
    else if(n=='+'||n=='-'){
        return 2;
    }
    else if(n=='*'||n=='/'){
        return 4;
    }
    else if(n=='^'){
        return 5;
    }
    else if(n>='a'&& n<='z'){
        return 8;
    }
    return -1;
}

int F_rank(char n){
    if (n == '(')
    {
        return 9;
    }
    else if(n==')'){
        return 0;
    }
    else if (n == '+' || n == '-')
    {
        return 1;
    }
    else if (n == '*'|| n == '/')
    {
        return 3;
    }
    else if (n == '^')
    {
        return 6;
    }
    else if (n >= 'a' && n <= 'z')
    {
        return 7;
    }
    return -1;
}

int Rank(char n){
    if (n == '+' || n == '-' || n == '*' || n == '/' || n == '^')
    {
        return -1;
    }
    else if (n >= 'a' && n <= 'z')
    {
        return 1; 
    }
    return 0;
}

char nextchar(char str[], int index)
{
    return str[index];
}

char stack[100];
int top = 0;

int isfull()
{
    if (top == 99)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char push(char n)
{
    if (isfull())
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = n;
        return n;
    }
}

char pop()
{
    if (isempty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        char temp = stack[top];
        top--;
        return temp;
    }
}

int main(){

    char str[]="(a+b^c^d)*(e+f/d)";
    char polish[100]="";
    int i=0, len = strlen(str);


    stack[++top]='(';

    int rank = 0;
    int polish_len = 0;

    char next = nextchar(str, i++);
    printf("polish notation is : ");
    while (next != '\0')
    {
        if (top<0)
        {
            printf("invalid String\n");
            break;
        }
        while(G_rank(stack[top])>F_rank(next)){
            char temp = pop();      
                printf("%c",temp);
                polish[polish_len] = temp;
                polish[polish_len + 1] = '\0';
                rank += Rank(temp);

                if (rank < 1)
                {
                    printf("invalid String\n");
                    break;
                }

        }
        if (G_rank(stack[top]) != F_rank(next))
        {
            push(next);
        }
        else
        {
            pop();
        }
        next = nextchar(str, i++);
    }


    if(top!=0 || rank != 1){
        printf("\n it is an invalid String\n");
    }
    else{
        printf("\n it is an valid string\n");
    }

    return 0;
}
