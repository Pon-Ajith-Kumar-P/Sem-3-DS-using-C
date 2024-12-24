#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int number;
    struct node *next;
}node;
node *list = NULL;

node *create_ll(node *list)
{
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
    return list; 
}

node *display_ll(node *list)
{
    printf("\nDisplaying the linked list\n");
    node *ptr = list;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->number);
        ptr=ptr->next;
    }
    return list;
}

node *insert_beg(node *list)
{
    int num;
    printf("\nEnter the value to be inserted at the beginning of the list : ");
    scanf("%d",&num);
    node *new = malloc(sizeof(node));
    new->number=num;
    new->next=list;
    list=new;
    return list;
}

node *insert_end(node *list)
{
    int num;
    printf("\nEnter the value to be inserted at the end of the list : ");
    scanf("%d",&num);
    node *end = malloc(sizeof(node));
    end->number=num;
    node *ptr = list;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = end;
    end->next = NULL;
    return list;
}

node *insert_bef(node *list)
{
    node *new = malloc(sizeof(node));
    int prenum,num;
    printf("\nEnter the value to be inserted : ");
    scanf("%d",&num);
    printf("\nEnter before which value %d to be inserted : ",num);
    scanf("%d",&prenum);
    new->number=num;
    node *ptr = list;
    node *prev = NULL;
    while(ptr->number != prenum)
    {
        prev=ptr;
        ptr = ptr->next;
    }
    prev->next = new;
    new->next = ptr;
    return list;
}

node *insert_aft(node *list)
{
    node *new = malloc(sizeof(node));
    int aftnum,num;
    printf("\nEnter the value to be inserted : ");
    scanf("%d",&num);
    printf("\nEnter after which value %d to be inserted : ",num);
    scanf("%d",&aftnum);
    new->number=num;
    node *ptr = list;
    while(ptr->number!=aftnum)
    {
        ptr=ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
    return list;
}

node *del_beg(node *list)
{
    node *ptr = list;
    list = list->next;
    free(ptr);
    return list;
}


node *del_end(node *list)
{
    node *ptr = list;
    node *prev = NULL;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }    
    prev->next=NULL;
    free(ptr);
    return list;
}

node *del_part(node *list)
{
    int num;
    printf("\nEnter which number to be deleted : ");
    scanf("%d",&num);
    node *ptr = list;
    node *prev = NULL;
    if(ptr->number==num)
    {
        list=del_beg(list);
        return list;
    }
    else
    {
        while(ptr->number!=num)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        free(ptr);
        return list;
    }
}

node *del_aft(node *list)
{
    int num;
    printf("\nEnter the value after which the node is to be deleted: ");
    scanf("%d", &num);
    node *ptr = list;
    while (ptr->number != num)
    {
        ptr = ptr->next;
    }
    node *nxtnode = ptr->next; 
    ptr->next = nxtnode->next;
    free(nxtnode);
    return list;
}

node *del_entire(node *list)
{
    while (list != NULL)
    {
        list = del_beg(list); 
    }
    return list;
}

node *sort_ll(node *list)
{
    node *ptr1, *ptr2;
    ptr1=list;
    while(ptr1 != NULL)
    {
        ptr2=ptr1->next;
        while(ptr2 != NULL)
        {
            int temp;
            if(ptr1->number > ptr2->number)
            {
                temp = ptr1->number;
                ptr1->number = ptr2->number;
                ptr2->number = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return list;
}

int main()
{
    int option;
    do
    {
        printf("\n---Main Menu---");
        printf("\n01. Create a linked list");
        printf("\n02. Displaying a linked list");
        printf("\n03. Add a node at the beginning");
        printf("\n04. Add a node at the end");
        printf("\n05. Add a node before the given node");
        printf("\n06. Add a node after the given node");
        printf("\n07. Delete a node at the beginning");
        printf("\n08. Delete a node at the end");
        printf("\n09. Delete a given node");
        printf("\n10. Delete after a given node");
        printf("\n11. Delete the entire list");
        printf("\n12. Sort the list");
        printf("\n13. Exit");
        printf("\nEnter an option : ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            list=create_ll(list);  
        break;
        case 2:
            list=display_ll(list);
        break;
        case 3:
            list=insert_beg(list);
        break;
        case 4:
            list=insert_end(list);
        break;
        case 5:
            list=insert_bef(list);
        break;
        case 6:
            list=insert_aft(list);
        break;
        case 7:
            list=del_beg(list);
        break;
        case 8:
            list=del_end(list);
        break;
        case 9:
            list=del_part(list);
        break;
        case 10:
            list=del_aft(list);
        break;
        case 11:
            list=del_entire(list);
        break;
        case 12:
            list=sort_ll(list);
        break;
        case 13:
            printf("\nThank You!");
        break;

        default:
            printf("\nInvalid Choice");
        break;
        }
    } while (option!=13);   
}