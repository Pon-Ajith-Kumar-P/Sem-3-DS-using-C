#include<stdio.h>
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
            printf("\nEnter A[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }    
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<j)
                sum+=arr[i][j];
        }
    }    
    printf("\nSum above main diagonal = %d",sum);
    return 0;
}
