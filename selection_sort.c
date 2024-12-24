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
    printf("\nSelection Sort\n");
    int pos;
    for(int i=0;i<n;i++)
    {
        pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[pos])
                pos=j;
        }
        int temp = arr[pos];
        arr[pos]=arr[i];
        arr[i]=temp;
    }
    printf("\nDisplaying the selection sorted array\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
}