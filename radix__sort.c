#include<stdio.h>
#include<stdlib.h>

void countsort(int a[],int n,int pos)
{

    int *count = (int*)malloc(10*sizeof(int));
    int *b = (int*)malloc(n*sizeof(int));
    if(count==NULL || b==NULL)
    {
        printf("\nError in memory allocation");
        free(count);
        free(b);
        return;
    }

    //Initialize count array elements to zero
    for(int i=0;i<10;i++)
    {
        count[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        count[(a[i]/pos)%10]++;
    }

    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }

    for(int i=n-1;i>=0;i--)
    {
        b[--count[(a[i]/pos)%10]]=a[i];
    }

    for(int i=0;i<n;i++)
    {
      a[i]=b[i];
    }

    free(b);
    free(count);
}

void radixsort(int a[],int n)
{
    int max = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    for(int pos=1;max/pos>0;pos*=10)
    {
        countsort(a,n,pos);
    }
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

    radixsort(a,n);

    printf("\nDisplaying %d elements in sorted order\n",n);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    
    free(a);
}