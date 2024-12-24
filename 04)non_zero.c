#include<stdio.h>
int main()
{
    int r,c;
    printf("\nEnter the number of rows : ");
    scanf("%d",&r);
    printf("\nEnter the number of cols : ");
    scanf("%d",&c);
    int arr[r][c];
    printf("Enter the elements in the 2-D array \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("\nEnter the element arr[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }    
    int non_zero = 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            ++non_zero;
        }
    }    
    printf("\nThe total number of non-zero elements = %d",non_zero);
    return 0;
}
