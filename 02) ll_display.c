#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int number;
    struct node *next;
}node;
int main()
{
    int num;
    printf("\nEnter the number (-1 to end) : ");
    scanf("%d",&num);
    node *list = NULL;
    while(num!=-1)
    {
        node *n = malloc(sizeof(node));
        n->number=num;
        if(list==NULL)
        {
            n->next = NULL;
            list = n;
        }
        else
        {
            node *tmp = list;
            while(tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = n;
            n->next = NULL;
            
        }
        printf("\nEnter the number (-1 to end) : ");
        scanf("%d",&num);
    }
    printf("\nDisplaying the linked list\n");
    node *ptr = list;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->number);
        ptr=ptr->next;
    }
}