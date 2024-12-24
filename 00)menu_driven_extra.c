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

node *traverse_l_r(node *list)
{
    node *ptr = list;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->number);
        ptr=ptr->next;
    }
    printf("Traversed from left to right successfully");
    return list;
}

node *traverse_r_l(node *list)
{
    if (list == NULL)
        return NULL;
    traverse_r_l(list->next); // Recursively go to the end of the list
    printf("%d\n", list->number);     // Print on the way back
    return list;
}

node *reverse_list(node *list)
{
    node *prev = NULL;
    node *current = list;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move the prev pointer one step forward
        current = next;       // Move the current pointer one step forward
    }

    return prev; // New head of the reversed list
}

node *length_ll(node *list)
{
    node *ptr = list;
    int count=0;
    while(ptr!=NULL)
    {
        ++count;
        ptr=ptr->next;
    }
    printf("The length of the linked list = %d",count);
    return list;
}

node *search(node *list)
{
    int val;
    printf("\nEnter the value to be searched : ");   
    scanf("%d",&val);
    node *ptr = list;
    int flag=0;
    while(ptr!=NULL)
    {
        if(ptr->number == val)
            flag=1;
        ptr=ptr->next;
    }
    if(flag==0)
    {
        printf("\nThe searched element was not found in the linked list");
    }
    if(flag==1)
    {
        printf("\nThe searched element was found in the linked list");
    }
    return list;
}

node *display_Nth_node_ll(node *list)
{
    int pos;
    printf("\nEnter the position of node to be displayed\n");
    scanf("%d",&pos);
    node *ptr = list;
    int count=0;
    while(ptr!=NULL)
    {
        ++count;
        if(pos==count)
        {
            printf("T\nThe value in the node position %d = %d\n",pos,ptr->number);
            break;
        }
        ptr=ptr->next;
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
        printf("\n03. Traversing from left to right");
        printf("\n04. Traversing from right to left");
        printf("\n05. Reverse the linked list");
        printf("\n06. Find length of the linked list");
        printf("\n07. Search an element in the linked list");
        printf("\n08. Get the Nth node of the list");
        printf("\n09. Exit");
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
            list=traverse_l_r(list);
        break;
        case 4:
            list=traverse_r_l(list);
        break;
        case 5:
            list=reverse_list(list);
        break;
        case 6:
            list=length_ll(list);
        break;
        case 7:
            list=search(list);
        break;
        case 8:
            list=display_Nth_node_ll(list);
        break;
        case 9:
            printf("\nThank You!");
        break;

        default:
            printf("\nInvalid Choice");
        break;
        }
    } while (option!=9);   
}