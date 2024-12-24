#include<stdio.h>
void readarray(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        printf("\nElement %d : ",i+1);
        scanf("%d",&arr[i]);
    }
}

void insertion(int n,int arr[])
{
    int j,key;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(arr[j]>key && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void disparray(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
int main()
{
    int n;
    printf("\nEnter the number of elements in the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter %d elements",n);
    readarray(n,arr);
    printf("\nDisplaying %d elements before sorting\n",n);
    disparray(n,arr);
    insertion(n,arr);
    printf("\nDisplaying %d elements after sorting\n",n);
    disparray(n,arr);

}