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
    int oddarr[r*c];
    int a=0;
    int evenarr[r*c];    
    int b=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]%2==0)
            {
                evenarr[b]=arr[i][j];
                ++b;
            }
            else
            {
                oddarr[a]=arr[i][j];
                ++a;
            }
        }
    }    
    printf("\nThe elements in the odd array are: ");
    for(int i=0;i<a;i++)
    {
        printf("%d\t",oddarr[i]);
    }
    printf("\nThe elements in the odd array are: ");
    for(int i=0;i<b;i++)
    {
        printf("%d\t",evenarr[i]);        
    }
    return 0;
}