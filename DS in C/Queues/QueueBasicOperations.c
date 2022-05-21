#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{ // Checking whether queue full or not
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct Queue *q, int val)
{ // inserting array from the queue
    if (isFull(q))
    {
        printf("Queue is full !\n");
    }
    else
    {
        q->r++;        //Linear Increment
        q->arr[q->r] = val;
        printf(" %d Enqueued !\n", q->arr[q->r]);
    }
    
}

int isEmpty(struct Queue *q)
{ // Checking whether queue full or not
    if (q->f == q->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue(struct Queue *q)
{ // Removing element from the queue
    int a = -1;
    if (isEmpty(q))
    {
        printf("No element to dequeue\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        return a;
    }    
}

int main()
{
    struct Queue q;
    q.size = 6;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 12);
    enqueue(&q, 14);
    enqueue(&q, 16);
    enqueue(&q, 18);
    enqueue(&q, 20);
    enqueue(&q, 22);

    printf("Element %d is dequeued from queue.\n", dequeue(&q));
    printf("Element %d is dequeued from queue.\n", dequeue(&q));

    printf("Element %d is dequeued from queue.\n", dequeue(&q));
    printf("Element %d is dequeued from queue.\n", dequeue(&q));

    

    // enqueue(&q,24);  //Now we cannot equeue another element because front == rear and if front goes to at last elemenet of queue then we cant move it further.

    // printf("queue is Empty.\n",isEmpty(&q)); //Now Both conditions are true because front == rear and rear = size -12this can be resolve in circular queue
    // printf("queue is Full.\n",isFull(&q));
    return 0;
}