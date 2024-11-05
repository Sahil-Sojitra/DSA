#include<stdio.h>

int binary_search(int arr[],int n,int key){
    int left=0;
    int right=n-1;
    int middle;

    while(left<=right){
        middle=(left+right)/2;
    if(arr[middle]==key){
        printf("%d is found at index %d\n",arr[middle],middle);
        return middle;
        }
        else if(arr[middle]>key){
            right=middle-1;
        }
        else{
            left=middle+1;
            }
    }
    return -1;
}
int main(){
    int arr[100];
    int n,i,result,key;

    printf("enter that how many number you want to add into the array : ");
    scanf("%d",&n);

    for(i=0; i<n; i++){
        printf("enter the number %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Enter the key element which you want to find out from the given array : ");
    scanf("%d",&key);

    result = binary_search(arr,n,key)

    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);

    return 0;
}