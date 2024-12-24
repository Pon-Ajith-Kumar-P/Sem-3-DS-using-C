#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order {
    char customerName[50];
    int orderID;
    struct Order *next;
} Order;

typedef struct Queue {
    Order *front;
    Order *rear;
} Queue;

typedef struct Stack {
    Order *top;
} Stack;

Queue* createQueue();
Stack* createStack();
void enqueue(Queue *q, char *name, int id);
void dequeue(Queue *q, Stack *s);
void displayQueue(Queue *q);
void push(Stack *s, char *name, int id);
void pop(Stack *s);
void displayStack(Stack *s);
void peekQueue(Queue *q);
void peekStack(Stack *s);
void freeQueue(Queue *q);
void freeStack(Stack *s);
int isEmptyQueue(Queue *q);
int isEmptyStack(Stack *s);

int main() {
    Queue *orderQueue = createQueue();
    Stack *deliveryStack = createStack();
    int choice, id;
    char name[50];

    while (1) {
        printf("\nOnline Order and Delivery Management System\n");
        printf("1. Enqueue Order\n");
        printf("2. Dequeue Order\n");
        printf("3. Peek Next Order\n");
        printf("4. Display Pending Orders\n");
        printf("5. Push Delivery\n");
        printf("6. Pop Delivery\n");
        printf("7. Peek Latest Delivery\n");
        printf("8. Display Delivery History\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%s", name);
                printf("Enter order ID: ");
                scanf("%d", &id);
                enqueue(orderQueue, name, id);
                break;
            case 2:
                if (!isEmptyQueue(orderQueue)) {
                    dequeue(orderQueue, deliveryStack);
                } else {
                    printf("Queue is empty. No orders to process.\n");
                }
                break;
            case 3:
                peekQueue(orderQueue);
                break;
            case 4:
                displayQueue(orderQueue);
                break;
            case 5:
                if (!isEmptyStack(deliveryStack)) {
                    printf("Enter customer name for delivery: ");
                    scanf("%s", name);
                    printf("Enter order ID for delivery: ");
                    scanf("%d", &id);
                    push(deliveryStack, name, id);
                } else {
                    printf("No recent orders to push for delivery.\n");
                }
                break;
            case 6:
                if (!isEmptyStack(deliveryStack)) {
                    pop(deliveryStack);
                } else {
                    printf("No deliveries to pop.\n");
                }
                break;
            case 7:
                peekStack(deliveryStack);
                break;
            case 8:
                displayStack(deliveryStack);
                break;
            case 9:
                freeQueue(orderQueue);
                freeStack(deliveryStack);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

Stack* createStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void enqueue(Queue *q, char *name, int id) {
    Order *newOrder = (Order *)malloc(sizeof(Order));
    strcpy(newOrder->customerName, name);
    newOrder->orderID = id;
    newOrder->next = NULL;

    if (q->rear == NULL) {
        q->front = newOrder;
        q->rear = newOrder;
    } else {
        q->rear->next = newOrder;
        q->rear = newOrder;
    }
    printf("Order added: %s (ID: %d)\n", name, id);
}

void dequeue(Queue *q, Stack *s) {
    Order *temp = q->front;
    printf("Processing order: %s (ID: %d)\n", temp->customerName, temp->orderID);
    push(s, temp->customerName, temp->orderID);

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void displayQueue(Queue *q) {
    if (q->front == NULL) {
        printf("No pending orders in the queue.\n");
        return;
    }
    Order *temp = q->front;
    printf("Pending Orders:\n");
    while (temp != NULL) {
        printf("Customer: %s, Order ID: %d\n", temp->customerName, temp->orderID);
        temp = temp->next;
    }
}

void push(Stack *s, char *name, int id) {
    Order *newOrder = (Order *)malloc(sizeof(Order));
    strcpy(newOrder->customerName, name);
    newOrder->orderID = id;
    newOrder->next = s->top;
    s->top = newOrder;
    printf("Delivery added: %s (ID: %d)\n", name, id);
}

void pop(Stack *s) {
    if (s->top == NULL) {
        printf("No deliveries to pop.\n");
        return;
    }
    Order *temp = s->top;
    printf("Delivery completed: %s (ID: %d)\n", temp->customerName, temp->orderID);
    s->top = s->top->next;
    free(temp);
}

void displayStack(Stack *s) {
    if (s->top == NULL) {
        printf("No delivery history.\n");
        return;
    }
    Order *temp = s->top;
    printf("Delivery History (most recent first):\n");
    while (temp != NULL) {
        printf("Customer: %s, Order ID: %d\n", temp->customerName, temp->orderID);
        temp = temp->next;
    }
}

void peekQueue(Queue *q) {
    if (q->front == NULL) {
        printf("No pending orders in the queue.\n");
        return;
    }
    printf("Next order to process: %s (ID: %d)\n", q->front->customerName, q->front->orderID);
}

void peekStack(Stack *s) {
    if (s->top == NULL) {
        printf("No deliveries made yet.\n");
        return;
    }
    printf("Latest delivery: %s (ID: %d)\n", s->top->customerName, s->top->orderID);
}

void freeQueue(Queue *q) {
    Order *temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

void freeStack(Stack *s) {
    Order *temp;
    while (s->top != NULL) {
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    free(s);
}

int isEmptyQueue(Queue *q) {
    return q->front == NULL;
}

int isEmptyStack(Stack *s) {
    return s->top == NULL;
}
