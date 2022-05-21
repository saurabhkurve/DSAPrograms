#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFullR(struct Queue *q)
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
void enqueueR(struct Queue *q, int val)
{ // inserting Data at rear in DEQueue
    if (isFullR(q))
    {
        printf("Queue is full !\n");
    }
    else
    {
        q->r++;        //Linear Increment
        q->arr[q->r] = val;
        printf(" %d Enqueued at rear !\n", q->arr[q->r]);
    }
    
}
int isFullF(struct Queue *q){
    if(q->f ==q->r){
        return 1;
    }else{
        return 0;
    }
}
void enqueueF(struct Queue *q, int val)
{ // inserting data at dront in DEQueue
    if (isFullF(q))
    {
        printf("Queue is full !\n");
    }
    else
    {   
        q->arr[q->f] = val;
        q->f--;
        printf(" %d Enqueued at front!\n", q->arr[q->f]);
    }
}

int isEmptyF(struct Queue *q)
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

int dequeueF(struct Queue *q)
{ // Removing element from the queue
    int a = -1;
    if (isEmptyF(q))
    {
        printf("No element to dequeue at front\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        return a;
    }    
}
int isEmptyR(struct Queue *q){
    if(q->r == q->size){
        return 1;
    }else{
        return 0;
    }
}
int dequeueR(struct Queue *q)
{ // Removing element from the queue
    int a = -1;
    if (isEmptyR(q))
    {
        printf("No element to dequeue at rear\n");
    }
    else
    {
        q->r--;
        a = q->arr[q->r];
        return a;
    }    
}
int main()
{
    struct Queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueueR(&q, 12);
    enqueueR(&q, 14);
    enqueueR(&q, 16);
    enqueueR(&q, 18);
    enqueueR(&q, 20);
    //enqueueR(&q, 22);

    printf("Element %d is dequeued from queue.\n", dequeueF(&q));
    printf("Element %d is dequeued from queue.\n", dequeueF(&q));
    printf("Element %d is dequeued from queue.\n", dequeueF(&q));
    printf("Element %d is dequeued from queue.\n", dequeueF(&q));

    

    enqueueF(&q,24);  //Now we cannot equeue another element because front == rear and if front goes to at last elemenet of queue then we cant move it further.
    printf("Element %d is dequeued from queue.\n", dequeueR(&q));
    // printf("queue is Empty.\n",isEmpty(&q)); //Now Both conditions are true because front == rear and rear = size -12this can be resolve in circular queue
    // printf("queue is Full.\n",isFull(&q));
    return 0;
}