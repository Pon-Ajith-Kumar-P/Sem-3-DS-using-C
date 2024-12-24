#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

node *head = NULL;

void addnode(int data)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int getcount()
{
    node *temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void display()
{
    if(head==NULL)
    {
        printf("\nEmpty");
        return;
    }
    node *temp = head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void insert_beg(int data)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;        
}

void insert_end(int data)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
        node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    
}

void insert_after_pos(int data,int pos)
{
    if(head==NULL)
    {
        printf("\nEmpty. Not possible");
        return;
    }
    if(pos>getcount())
    {
        printf("\nInvalid Position. Try again");
        return;
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    int i=1;
    node *temp = head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_before_pos(int data,int pos)
{
    if(head==NULL)
    {
        printf("\nList is Empty. Not possible");
        return;
    }
    if(pos>getcount())
    {
        printf("\nInvalid Position");
        return;
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    int i=1;
    node *temp = head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_after_num(int data,int val)
{
    if(head==NULL)
    {
        printf("\nEmpty list. Not possible");
        return;
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    node *temp = head;
    while(temp->data !=val)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_before_num(int data,int val)
{
    if(head==NULL)
    {
        printf("\nEmpty list. Not possible");
        return;
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    node *ptr = head;
    node *preptr;
    while(ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }    
    newnode->next = preptr->next;
    preptr->next = newnode;
}

void delete_beg()
{
    node *temp = head;
    head = head->next;
    free(temp);
}

void delete_end()
{
    node *ptr = head;
    node *preptr = NULL;
    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    preptr->next = NULL;
}

void delete_at_val(int val)
{
    node *ptr = head;
    node *preptr = NULL;
    if(ptr->data == val)
    {
        delete_beg();
    }    
    else
    {
        while(ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        free(ptr);
        preptr->next = NULL;
    }
}

void reverse_ll()
{
    node *prev = NULL;
    node *current = head;
    node *nextnode = NULL;
    while(current!=NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;
}

void freelist()
{
    while(head!=NULL)
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
    printf("\nLL deallocated successfully");

}

int main()
{
    int choice;
    int num,pos,val;
    do{
        printf("\n-----Main Menu-----");
        printf("\n1. Adding a data/node the linked list");
        printf("\n2. Displaying the linked list");        
        printf("\n3. Insert at the beginning");        
        printf("\n4. Insert at the end");        
        printf("\n5. Insert after the given position");        
        printf("\n6. Insert before the given position");        
        printf("\n7. Insert after the given value");        
        printf("\n8. Insert before the given value");        
        printf("\n9. Delete at the beginning");        
        printf("\n10. Delete at the end");        
        printf("\n11. Delete after the given position");        
        printf("\n12. Count of nodes in linked list");
        printf("\n13. Exit");
        printf("\n14.Reverse of the LL");
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the number to be added : ");
            scanf("%d",&num);
            addnode(num);
            break;
        case 2:
            display();
            break;

        case 3:
            printf("\nEnter the value to be added : ");
            scanf("%d",&num);
            insert_beg(num);
            break;            

        case 4:
            printf("\nEnter the value to be added : ");
            scanf("%d",&num);
            insert_end(num);
            break;            

        case 5:
            printf("\nEnter the value to be added : ");
            scanf("%d",&num);
            printf("\nEnter the position after which to be added : ");
            scanf("%d",&pos);
            insert_after_pos(num,pos);
            break;            

        case 6:
            printf("\nEnter the value to be added : ");
            scanf("%d",&num);
            printf("\nEnter the position before which to be added : ");
            scanf("%d",&pos);
            insert_before_pos(num,pos);
            break;            

        case 7:
            printf("\nEnter the value to be added : ");
            scanf("%d",&num);
            printf("\nEnter the val after which to be added : ");
            scanf("%d",&val);
            insert_after_num(num,val);
            break;            

        case 8:
            printf("\nEnter the value to be added : ");
            scanf("%d",&num);
            printf("\nEnter the val before which to be added : ");
            scanf("%d",&val);
            insert_before_num(num,val);
            break;            

        case 9:
            delete_beg(num);
            break;            

        case 10:
            delete_end(num);
            break;            

        case 11:
            printf("\nEnter the val at which to be deleted : ");
            scanf("%d",&val);
            delete_at_val(val);
            break;                    

        case 12:
            printf("\nCount of nodes = %d\n",getcount());
            break;

        case 13:
            freelist();
            printf("\nThank You");
            break;

        case 14:
            reverse_ll();
            break;

        default:
            printf("\nInvalid Input");
            break;
        }
    }while(choice!=13);


}