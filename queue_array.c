#include<stdio.h>
#define MAX 5
typedef struct queue
{
    int q[MAX];
    int front,rear;
}queue;
void init(queue *q)
{
    q->front = -1;
    q->rear = -1;
}
int main()
{
}