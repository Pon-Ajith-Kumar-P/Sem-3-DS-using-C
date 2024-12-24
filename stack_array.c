#include<stdio.h>
#define MAX 5
typedef struct stack
{
    int data[MAX];
    int top;
}stack;

void init(stack *s)
{
    s->top = -1;
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

int isFull(stack *s)
{
    return s->top == MAX-1;
}

void push(stack *s,int val)
{
    s->data[++(s->top)] = val;
    printf("\nPushed : %d",val);
}

int pop(stack *s)
{
    return s->data[(s->top)--];
}

int peek(stack *s)
{
    return s->data[s->top];
}

void display(stack *s)
{
    printf("\nStack Elements \n");
    for(int i=s->top;i>=0;i--)
    {
        printf("%d\t",s->data[i]);
    }
}

int main()
{
    stack s;
    init(&s);
    int option;
    do
    {
        printf("\n-----Main Menu-----");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter the option : ");
        scanf("%d",&option);
        
        switch(option)
        {
            case 1:
                push(&s,10);
            break;

            case 2:
                printf("\nPopped : %d",pop(&s));
            break;

            case 3:
                printf("\nPeeked : %d",peek(&s));
            break;

            case 4:
                display(&s);
            break;

            case 5:
                return 0;
            break;

            default:
                return 0;
            break;
        }

    } while (option!=5);
    
}