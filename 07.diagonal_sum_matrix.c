#include<stdio.h>
int main()
{
    int n;
    printf("\nEnter rows & cols in martix A : ");
    scanf("%d",&n);
    int arr[n][n];
    printf("Enter elements in the matrix A \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nEnter A[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }    
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                sum+=arr[i][j];
        }
    }    
    printf("\nThe sum of the diagonal elements = %d",sum);
    return 0;
}