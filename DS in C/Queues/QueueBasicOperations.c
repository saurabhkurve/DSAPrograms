#include<stdio.h>
#include <stdlib.h>
struct Queue{
    int size;
    int f;
    int r;
    int *arr;
};
 
int isFull(struct Queue *q){   //Checking whether queue full or not
    if(q->r == q->size - 1){
        return 1;
    }else{
        return 0;
    }
}
void enqueue(struct Queue *q,int val){  //inserting array from the queue
    if(isFull(q)){
        printf("Queue Overflow !");
    }else{
        q->r++;
        q->arr[q->r] = val;
    }
    printf(" %d Enqueued !\n",q->arr[q->r]);
}

int isEmpty(struct Queue *q){   //Checking whether queue full or not
    if(q->f == q->r){
        return 1;
    }else{
        return 0;
    }
}

int dequeue(struct Queue *q){   //Removing element from the queue
    int a = -1;
    if(isEmpty(q)){
        printf("No element to dequeue");
        return a;
    }else{
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}

int main(){
    struct Queue q;
    q.size  = 10;
    q.f= q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q,12);
    enqueue(&q,14);
    enqueue(&q,16);
    enqueue(&q,18);
    enqueue(&q,20);
    enqueue(&q,22);

    printf("Element %d is dequeued from queue.\n",dequeue(&q));

    
    return 0;
}