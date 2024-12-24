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
    printf("\nDisplaying the sorted array\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);

    int mid,beg=0,end=n-1,pos=-1;
    int val;
    printf("\nEnter the value to be searched : ");
    scanf("%d",&val);
    int flag=0;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(arr[mid]==val)
        {
            pos = mid;
            flag=1;
            break;    
        }
        if(arr[mid]>val)
            end = mid-1;
        if(arr[mid]<val)
            beg = mid + 1;
    }
    if(flag==1)
        printf("\nThe element found in the array position %d",pos);
    else
        printf("\nThe element not found");
}