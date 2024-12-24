#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front, rear;
} Deque;

void initDeque(Deque *d) {
    d->front = -1;
    d->rear = -1;
}

int isFull(Deque *d) {
    return (d->front == 0 && d->rear == MAX - 1) || (d->front == d->rear + 1);
}

int isEmpty(Deque *d) {
    return d->front == -1;
}

void insertFront(Deque *d, int value) {
    if (isFull(d)) {
        printf("Deque is full\n");
        return;
    }
    if (d->front == -1) {
        d->front = 0;
        d->rear = 0;
    } else if (d->front == 0) {
        d->front = MAX - 1;
    } else {
        d->front--;
    }
    d->items[d->front] = value;
}

void insertRear(Deque *d, int value) {
    if (isFull(d)) {
        printf("Deque is full\n");
        return;
    }
    if (d->rear == -1) {
        d->front = 0;
        d->rear = 0;
    } else if (d->rear == MAX - 1) {
        d->rear = 0;
    } else {
        d->rear++;
    }
    d->items[d->rear] = value;
}

int deleteFront(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return -1;
    }
    int item = d->items[d->front];
    if (d->front == d->rear) {
        d->front = d->rear = -1; // Reset the deque
    } else if (d->front == MAX - 1) {
        d->front = 0;
    } else {
        d->front++;
    }
    return item;
}

int deleteRear(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return -1;
    }
    int item = d->items[d->rear];
    if (d->front == d->rear) {
        d->front = d->rear = -1; // Reset the deque
    } else if (d->rear == 0) {
        d->rear = MAX - 1;
    } else {
        d->rear--;
    }
    return item;
}

void displayDeque(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return;
    }
    int i = d->front;
    do {
        printf("%d ", d->items[i]);
        i = (i + 1) % MAX;
    } while (i != (d->rear + 1) % MAX);
    printf("\n");
}

int main() {
    Deque d;
    initDeque(&d);
    insertRear(&d, 10);
    insertRear(&d, 20);
    insertFront(&d, 30);
    displayDeque(&d);
    printf("Deleted from front: %d\n", deleteFront(&d));
    displayDeque(&d);
    printf("Deleted from rear: %d\n", deleteRear(&d));
    displayDeque(&d);
    return 0;
}
