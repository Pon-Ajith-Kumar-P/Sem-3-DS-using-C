#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int number;
    struct node *next;
} node;
int main()
{
    node *list = NULL;
    int num;
    printf("\nEnter a number (-1 to end) : ");
    scanf("%d",&num);
    while(num!=-1)
    {
        node *n = malloc(sizeof(node));
        n->number = num;
        
        if(list==NULL)
        {
            n->next = NULL;
            list = n;
        }
        
        else 
        {
            node *temp = malloc(sizeof(node));
            temp = list;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->next = NULL;
        }

    printf("\nEnter a number (-1 to end) : ");
    scanf("%d",&num);

    }
}