#include<stdio.h>
int main()
{
    int arr1[25],arr2[25];
    int n1,n2;

    printf("\nEnter the no. of elements in array 1 : ");
    scanf("%d",&n1);
    printf("\nEnter %d elements in array 1 (sorted manner)\n",n1);
    for(int i=0;i<n1;i++)
        scanf("%d",&arr1[i]);

    printf("\nEnter the no. of elements in array 2 : ");
    scanf("%d",&n2);
    printf("\nEnter %d elements in array 2 (sorted manner)\n",n2);
    for(int i=0;i<n2;i++)
        scanf("%d",&arr2[i]);

    printf("\nDisplaying the array 1\n");
    for(int i=0;i<n1;i++)
        printf("%d\t",arr1[i]);
    
    printf("\nDisplaying the array 2\n");
    for(int i=0;i<n2;i++)
        printf("%d\t",arr2[i]);
    
    int n3=n1+n2;
    int arr3[n3];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
            arr3[k++]=arr1[i++];
        else
            arr3[k++]=arr2[j++];
    }
    while(i<n1)
    {
        arr3[k++]=arr1[i++];
    }
    while(j<n2)
    {
        arr3[k++]=arr2[j++];
    }
    printf("\nDisplaying the merge sorted array\n");
    for(int i=0;i<n3;i++)
        printf("%d\t",arr3[i]);
       

}