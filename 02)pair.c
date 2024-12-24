#include<stdio.h>
int main()
{
    int n;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i]+arr[j]==50)
                printf("\nThe array pair (%d,%d) gives the sum 50",arr[i],arr[j]);
        }
    }
}