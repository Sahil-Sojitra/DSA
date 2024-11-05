#include<conio.h>
#include<math.h>
#include<stdio.h>


// The concept of the call of the values 


// void swapxy(int x,int y){
//     int temp;
//     temp=x;
//     x=y;
//     y=temp;
//     printf("The altered numbers are %d and %d",x,y);
// }
// int main(){
//     int x,y;

//     printf("Enter the value of the x :");
//     scanf("%d",&x);

//     printf("Enter the value of the y : ");
//     scanf("%d",&y);
// printf("The numbers are %d and %d\n", x, y);
//     swapxy(x,y);

//     return 0;
// }

// the concept of the call by reference
void swapxy(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    printf("The altered numbers are %d and %d",*x,*y);
}
int main(){
    int x,y;

    printf("Enter the value of the x :");
    scanf("%d",&x);

    printf("Enter the value of the y : ");
    scanf("%d",&y);
    printf("The numbers are %d and %d\n",x,y);

    swapxy(&x,&y);

    return 0;
}