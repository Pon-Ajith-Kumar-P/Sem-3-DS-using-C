#include<stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int low,int high)
{
    int pivot = arr[low];
    int start = low;
    int end = high;

    while(start<end)
    {
        while(arr[start]<=pivot && start < high)
            ++start;
        while(arr[end]>=pivot && end > low)
            --end;
        if(start<end)
            swap(&arr[start],&arr[end]);
    }
    swap(&arr[low],&arr[end]);
    return end;
}

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main() 
{  
    int arr[25];
    int n;
    printf("\nEnter the size of the array : ");
    scanf("%d",&n);
    printf("\nEnter %d elements ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nDisplaying unsorted array\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("\nDisplaying quick sorted array\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    return 0;
}