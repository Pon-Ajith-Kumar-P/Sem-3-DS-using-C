#include<stdio.h>
#include<stdlib.h>
#define M 10
// Define the structure of the node
typedef struct node{
    int value;
    struct node *next;
}node;
// Define the hash function
int h(int x)
{
    return (x%M);
}
// Function to initialize the hash table
void initHT(node *hash_table[],int m)
{
    for(int i=0;i<m;i++)
        hash_table[i] = NULL;
}
// Function to insert a value into the hash table
void insert_value(node *hash_table[],int val)
{
    int i = h(val);
    node *new = malloc(sizeof(node));
    new->value = val;
    new->next = hash_table[i];
    hash_table[i] = new;
    printf("\nValue %d inserted successfully.\n",val);
}

void display(node *hash_table[],int m)
{
    for(int i=0;i<m;i++)
    {
        printf("[%d] : ",i);
        node *ptr = hash_table[i];
        while(ptr!=NULL)
        {
            printf("%d -> ",ptr->value);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

void search_value(node *hash_table[],int val)
{
    int index = h(val);
    node *ptr = hash_table[index];
    while(ptr!=NULL)
    {
        if(ptr->value == val)
        {
            printf("\nValue %d found successfully in the hash table",val);
            return;
        }
        ptr=ptr->next;
    }
    printf("\nValue %d not found in the hash table",val);
}

void delete_value(node *hash_table[],int val)
{
    int index = h(val);
    node *ptr = hash_table[index];
    node *preptr = NULL;
    while(ptr!=NULL)
    {
        if(ptr->value==val)
        {
            if(preptr==NULL)
                hash_table[index]=ptr->next;
            else
                preptr->next = ptr->next;
            free(ptr);
            printf("\nValue %d deleted successfully",val);
            return;
        }
        preptr = ptr;
        ptr = ptr->next;
    }
    printf("\nValue %d not found in the hash table",val);
}

int main()
{
    int choice,value;
    node *hash_table[M];
    initHT(hash_table,M);

        while (1) 
        {
            printf("\n=== MENU ===\n");
            printf("1. Insert Value\n");
            printf("2. Search Value\n");
            printf("3. Delete Value\n");
            printf("4. Display Hash Table\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&value);
                insert_value(hash_table,value);
                break;

            case 2:
                printf("Enter value to search : ");
                scanf("%d",&value);
                search_value(hash_table,value);
                break;

            case 3:
                printf("Enter value to delete : ");
                scanf("%d",&value);
                delete_value(hash_table,value);
                break;

            case 4:
                display(hash_table,M);
                break;

            case 5:
                printf("\nExit the program");
                return 0;
                break;

            default:
                printf("\nInvalid choice");
                break;
            }
        }
}