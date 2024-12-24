#include<stdio.h>
int main()
{
    int n;
    printf("\nEnter number of rows and cols in martix A and B : ");
    scanf("%d",&n);
    int arr1[n][n], arr2[n][n], sum_arr[n][n];

    printf("Enter the elements in the matrix A \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nEnter A[%d][%d] : ",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }

    printf("Enter the elements in the matrix B \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nEnter B[%d][%d] : ",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }    
    int x,y;
    printf("\nEnter the value of x : ");
    scanf("%d",&x);
    printf("\nEnter the value of y : ");
    scanf("%d",&y);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr1[i][j] = x * arr1[i][j];
            arr2[i][j] = y * arr2[i][j];
            sum_arr[i][j] = arr1[i][j]+arr2[i][j];
            printf("%d\t",sum_arr[i][j]);
        }
        printf("\n");
    }    
    return 0;
}