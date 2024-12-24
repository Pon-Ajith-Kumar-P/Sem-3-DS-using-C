#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

node *head = NULL;

void addnode(int data)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
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
        temp->next=newnode;
        newnode->prev=temp;
    }
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

int getcount()
{
    node *temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_beg(int data)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    if(head!=NULL)
        head->prev = newnode;
    head = newnode;
}

void insert_end(int data)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if(head == NULL)
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
        newnode->prev = temp;
    }
}

void insert_after_pos(int num,int pos)
{
    if(head==NULL)
    {
        printf("\nEmpty. Not possible");
        return;
    }
    if(pos>getcount() || pos<=0)
    {
        printf("\nInvalid Position. Try again");
        return;
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = num;
    node *temp = head;
    int i=1;
    while(i<pos)
    {
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

void insert_before_pos(int num,int pos)
{
    if(head==NULL)
    {
        printf("\nEmpty. Not possible");
        return;
    }
    if(pos>getcount() || pos<=0)
    {
        printf("\nInvalid Position. Try again");
        return;
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = num;
    if(pos==1)
    {
        newnode->prev = NULL;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    else
    {
        node *temp = head;
        int i=1;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        if(temp->next != NULL)
            temp->next->prev = newnode;
        temp->next = newnode;
    }

}

void insert_after_num(int num,int val)
{
    if(head==NULL)
    {
        printf("\nEmpty. Not possible");
        return;
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = num;
    node *temp = head;
    while(temp->data != val)
    {
        temp = temp->next;
    }    
    newnode->prev = temp;
    newnode->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

void insert_before_num(int num,int val)
{
    if(head==NULL)
    {
        printf("\nEmpty. Not possible");
        return;
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = num;
    if(head->data == val)
    {
        newnode->prev = head;
        newnode->next = head->next;
        head->prev = newnode;
        head = newnode;        
    }
    else
    {
        node *ptr = head;
        node *preptr;
        while(ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }    
        newnode->prev = preptr;
        newnode->next = preptr->next;
        if(preptr->next != NULL)
            preptr->next->prev = newnode;
        preptr->next = newnode;
    }
}

void delete_beg()
{
    node *temp = head;
    head = head->next;
    head->prev = NULL;
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
        if(ptr->next!=NULL)
            ptr->next->prev = preptr->next;
        preptr->next = ptr->next;
    }
}

void freelist()
{
    while(head!=NULL)
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
    printf("\nDLL deallocated successfully");

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
        default:
            printf("\nInvalid Input");
            break;
        }
    }while(choice!=13);

}