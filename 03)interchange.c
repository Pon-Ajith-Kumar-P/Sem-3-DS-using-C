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
    int temp=arr[1];
    arr[1]=arr[n-2];
    arr[n-2]=temp;
    printf("\nThe array elements after interchanging elements \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}