#include<stdio.h>

void swap(int *j, int *i){
    int temp = *j;
    *j = *i;
    *i = temp;
}

void bubble_sort(int arr[],int n, int pass,int last){
    int i,j,temp,exch;

    for(i=0; i<n; i++){
        exch=0;
        for(j=0; j<n; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                exch++;
        }
    }
}
}

void printArray(int arr[],int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[100];
    int n,i;

    printf("Enter the number of the element in the array : ");
    scanf("%d",&n);

    for(i=0; i<n; i++){
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    bubble_sort(arr,n,0,n-1);
    printArray(arr, n);
    return 0;
}