#include<stdio.h>

void merge(int arr[],int n,int l,int m,int h){
    int i,j,k;
    int n1=m-l+1;
    int n2=h-m;

    int L[n1],R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int n,int l,int h){
    if(l<h){
        int m;
        m=(l+h)/2;
        merge_sort(arr,n,l,m);
        merge_sort(arr,n,m+1,h);
        merge(arr,n,l,m,h);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[100];
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    merge_sort(arr,n,0,n-1);
    printArray(arr,n);
return 0;
}