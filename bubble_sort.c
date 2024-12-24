#include<stdio.h>
int main()
{
    int arr[25];
    int n;
    printf("\nEnter the no. of elements : ");
    scanf("%d",&n);
    printf("\nEnter %d elements in array\n",n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nDisplaying the unsorted array\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\nBubble Sorting");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nDisplaying the bubble sorted array\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
}
