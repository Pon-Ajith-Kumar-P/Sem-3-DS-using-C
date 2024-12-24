#include<stdio.h>
int main()
{
    int arr[10];
    printf("\nEnter 10 elements ");
    for(int i=0;i<10;i++)
        scanf("%d",&arr[i]);
    printf("\nDisplaying 10 elements ");
    for(int i=0;i<10;i++)
        printf("%d\t",arr[i]);
    
    int num;
    printf("\nEnter the number to be found : ");
    scanf("%d",&num);

    int flag=0;
    for(int i=0;i<10;i++)
    {
        if(arr[i]==num)
        {
            flag=1;
            printf("\nElement found at the array position %d",i);
        }
    }
    if(flag==0)
        printf("\nThe element not found in the array");
}