#include<stdio.h>
#include<stdlib.h>
void countsort(int a[],int n)
{
    int max = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
            max = a[i];
    }

    int *count = (int*)malloc((max+1)*sizeof(int));
    //int count[max+1];
    int *b = (int*)malloc(n*sizeof(int));
    //int b[n];
    if(count==NULL || b==NULL)
    {
        printf("\nError in memory allocation");
        free(count);
        free(b);
        return;
    }

    //Initialize count array elements to zero
    for(int i=0;i<max+1;i++)
    {
        count[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }

    for(int i=1;i<=max;i++)
    {
        count[i]=count[i]+count[i-1];
    }

    for(int i=n-1;i>=0;i--)
    {
        b[--count[a[i]]]=a[i];
    }

    for(int i=0;i<n;i++)
    {
      a[i]=b[i];
    }

    free(b);
    free(count);
}
int main()
{
    int n;
    printf("\nEnter no. of elements in array : ");
    scanf("%d",&n);
    int *a = (int *)malloc(n * sizeof(int));
    //int a[n];
    if(a==NULL)
    {
        printf("\nError in memory allocation");
        free(a);
        return 1;
    }
    printf("\nEnter %d elements\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    countsort(a,n);

    printf("\nDisplaying %d elements in sorted order\n",n);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    
    free(a);
}