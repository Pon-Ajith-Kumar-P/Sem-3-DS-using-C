#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

node *head = NULL;
node *tail = NULL;

void addnode(int data)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    if(head==NULL)
    {
        head = newnode;
        tail = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
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
    do 
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }while(temp!=head);
}

int getcount()
{
    int count = 0;
    if(head == NULL)
    {
        return 0;
    }
    node *temp = head;
    do
    {
        count++;
        temp=temp->next;
    } while (temp!=head);
    return count;    
}

void insert_beg(int data)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}

void insert_end(int data)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    }  
    else
    {
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        tail = newnode; 
    }
}

void insert_after_pos(int data,int pos)
{
    if(head == NULL)
    {
        printf("\nEmpty. Not possible");
        return;
    }
    if(pos<=0 || pos>getcount())
    {
        printf("\nInvalid position");
        return;
    } 
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    node *temp = head;
    int i=1;
    while(i<pos)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next != head)
        temp->next->prev = newnode;
    temp->next = newnode; 
    if(temp == tail)
        tail = newnode;
}

void insert_before_pos(int data,int pos)
{
    if(tail == NULL)
    {
        printf("\nEmpty. Not possible");
        return;
    }
    if(pos<=0 || pos>getcount())
    {
        printf("\nInvalid position");
        return;
    } 
    if(pos==1)
    {
        insert_beg(data);
        return;
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    node *temp = tail->next;
    int i=1;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next != head)
        temp->next->prev = newnode;
    temp->next = newnode;
    if(temp==tail)
        tail = newnode;
}

void insert_after_num(int data,int num)
{
    if(tail == head)
    {
        printf("\nEmpty. Not possible");
        return;
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    node *temp = head;
    while(temp->data != num)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next != head)
        temp->next->prev = newnode;
    temp->next = newnode;
    if(temp==tail)
        tail = newnode;
}

void insert_before_num(int data,int num)
{
    if(tail == head)
    {
        printf("\nEmpty. Not possible");
        return;
    }
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
        node *ptr = head;
        node *preptr = NULL;
        while(ptr->data != num)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        newnode->next = ptr;
        newnode->prev = preptr;
        if(ptr != head)
            ptr->prev = newnode;
        preptr->next = newnode;
        if(ptr==tail)
            tail = newnode;
}

void delete_beg()
{
    if(head==tail)
    {
        head = tail = NULL;
        free(head);
    }
    else
    {
        node *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }

}

void delete_end()
{
    if(head==tail)
    {
        head = tail = NULL;
        free(head);
    }
    else
    {
        node *ptr = head;
        while(ptr->next != tail)
        {
            ptr=ptr->next;
        }
        tail = ptr;
        tail->next = head;
        head->prev = tail;
        free(ptr->next);
    }

}

void delete_at_val(int val)
{
    if(head->data == val)
    {
        delete_beg();
        return;
    }
    node *ptr = head;
    node *preptr = NULL;
    while(ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    if(ptr==tail)
    {
        tail = preptr;
        tail->next = head;
        head->prev = tail;
    }
}

void freelist()
{
    if(head==NULL)
        return;
    node *temp = head;
    node *nextNode;
    do
    {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }while(temp!=head);
    head = tail = NULL;
    printf("\nCDLL deallocated successfully");

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