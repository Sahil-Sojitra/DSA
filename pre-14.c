#include <stdio.h>

int partition(int arr[], int LB, int UB)
{
    int pivot = arr[LB];
    int i = LB + 1, j = UB;
        while (i <= j)
        {
            while (arr[i] <= pivot)
            {
                i++;
            }
            while (arr[j] > pivot)
            {
                j--;
            }
            if (i <= j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp1 = arr[LB];
        arr[LB] = arr[j];
        arr[j] = temp1;
        return j;
}

    void quick_sort(int arr[], int LB, int UB)
    {
        if (LB < UB)
        {
            int pivot = partition(arr, LB, UB);
            quick_sort(arr, LB, pivot-1);
            quick_sort(arr, pivot + 1, UB);
        }
    }
    void printArray(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    int main()
    {
        int arr[100];
        int n, i;
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            printf("Enter element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }

        quick_sort(arr, 0, n - 1);
        printArray(arr, n);
        return 0;
    }
