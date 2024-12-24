#include<stdio.h>
#define N 25
int main()
{
    int arr1[N],arr2[N];
    int n1,n2;
    printf("\nEnter number of elements in array 1 : ");
    scanf("%d",&n1);
    printf("\nEnter number of elements in array 2 : ");
    scanf("%d",&n2);
    
    printf("\nEnter %d elements in array 1\n ",n1);
    for(int i=0;i<n1;i++)
    {
        printf("\nElement %d : ",i+1);
        scanf("%d",&arr1[i]);
    }

    printf("\nEnter %d elements in array 2\n ",n2);
    for(int i=0;i<n2;i++)
    {
        printf("\nElement %d : ",i+1);
        scanf("%d",&arr2[i]);
    }

    int merge[n1+n2];
    for(int i=0;i<n1;i++)
    {
        merge[i]=arr1[i];
    }
    for(int j=0;j<n2;j++)
    {
        merge[n1+j]=arr2[j];
    }

    printf("\nDisplaying %d Elements in reverse order \n",n1+n2);
    for(int i=n1+n2-1;i>=0;i--)
    {
        printf("%d\t",merge[i]);
    }
    return 0;
}