#include<stdio.h>
int check(int n,int arr[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=arr[j][i])
                return 0;
        }
    }    
    return 1;
}
int main()
{
    int n;
    printf("\nEnter no. of rows & cols in martix A : ");
    scanf("%d",&n);
    int arr[n][n];
    printf("Enter elements in matrix A \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nEnter the matrix element A[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }    
    if(check(n,arr)==1)
        printf("\nThe given matrix is a symmetric matrix");
    else
        printf("\nThe given matrix is a not symmetric matrix");
    return 0;
}
