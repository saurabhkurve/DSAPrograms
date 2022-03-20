#include <stdio.h>
#include <stdlib.h>
struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct CircularQueue *q)
{ // Checking whether queue full or not
    if ((q->r + 1)% q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct CircularQueue *q, int val)
{ // inserting array from the queue
    if (isFull(q))
    {
        printf("Queue is full !\n");
    }
    else
    {
        q->r = (q->r+1)%q->size;  //Circular increment
        q->arr[q->r] = val;
        printf(" %d Enqueued !\n", q->arr[q->r]);
    }
}

int isEmpty(struct CircularQueue *q)
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

int dequeue(struct CircularQueue *q)
{ // Removing element from the queue
    int a = -1;
    if (isEmpty(q))
    {
        printf("No element to dequeue\n");
    }
    else
    {
        q->f = (q->f+1)%q->size;;
        a = q->arr[q->f];
        return a;
    }
}

int main()
{
    struct CircularQueue q;
    q.size = 7;
    q.f = q.r = 0;
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

    printf("Element %d is dequeued from queue.\n", dequeue(&q));
    printf("Element %d is dequeued from queue.\n", dequeue(&q));

    enqueue(&q, 21);
    enqueue(&q, 42);
    enqueue(&q, 63);
    enqueue(&q, 84);
    enqueue(&q, 50);
    enqueue(&q, 92);

    printf("Element %d is dequeued from queue.\n", dequeue(&q));
    printf("Element %d is dequeued from queue.\n", dequeue(&q));

    enqueue(&q, 50);
    enqueue(&q, 92);

    return 0;
}