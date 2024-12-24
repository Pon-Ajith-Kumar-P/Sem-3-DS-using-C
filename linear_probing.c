#include<stdio.h>
#define M 10

int ht[M];
int found = 0;
int key;

int h(int x)
{
    return (x%M);
}

void insert(int val)
{
    int index = h(val);
    for(int i=0;i<M;i++)
    {
        int probe = (index+i)%M;
        if(ht[probe]==-1)
        {
            ht[probe] = val;
            printf("\nInserted %d successfully",val);
            return;
        }
    }
    printf("\nHash Table is full");
}

void search(int val)
{
    int index = h(val);
    for(int i=0;i<M;i++)
    {
        int probe = (index+i)%M;
        if(ht[probe]==val)
        {
            printf("\nValue %d found successfully at probe %d",val,probe);
            found = 1;
            key = probe;
            return;
        }
    }
    printf("\nValue not found in the Hash Table");
}

void delete(int val)
{
    search(val);
    if(found == 1 && key != -1)
    {
        ht[key] = -1;
        printf("\nValued %d deleted from probe %d",val,key);
    }
    else
    {
        printf("\nDeletion Failed");
    }
}

void display()
{
    for(int i=0;i<M;i++)
    {
        if(ht[i]==-1)
            printf("[%d] : EMPTY\n",i);
        else
            printf("[%d] : %d\n",i,ht[i]);
    }
}


int main()
{
    int choice,val;
    //Initialize with the sentinel values
    for(int i=0;i<M;i++)
    {
        ht[i] = -1;
    }

    while(1)
    {
        printf("\n==Menu==");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("\nEnter a value to insert : ");
            scanf("%d",&val);
            insert(val);
            break;

            case 2:
            printf("\nEnter a value to search : ");
            scanf("%d",&val);
            search(val);
            break;

            case 3:
            printf("\nEnter a value to delete : ");
            scanf("%d",&val);
            delete(val);
            break;
            
            case 4:
            display();
            break;

            case 5:
                printf("\nExit");
                return 0;
            break;

            default:
                printf("\nInvalid Choice");
       }
    }
    return 0;
}