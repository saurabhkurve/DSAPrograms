#include<stdio.h>
#include <stdlib.h>



struct node{
    int data;
    struct node *next;
};
struct node *f = NULL;
struct node *r= NULL;

void Traversal(struct node *f){
    //printf("Hello");
    while( f!= NULL){
        printf("Element:%d\n",f->data);
        f=f->next;
    }
}

void enqueue(int val){          //enqueue i.e.insert node at last
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n== NULL){
        printf("Queue is full\n");
    }else{
        n->data = val;
        n->next=NULL;
        if(f == NULL){
            f=r=n;
        }else{
            r->next=n;
            r=n;
        }
    }
}

int dequeue(){     //dequeue i.e.removing node from beginning
    int val =-1;
    struct node *ptr = f;
    if(f== NULL){
        printf("Queue is empty!\n");
    }else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main(){
    
    printf("Before Enquing :\n");
    Traversal(f);

    printf("dequing element = %d\n",dequeue());

    enqueue(12);
    enqueue(16);
    
    printf("After Enquing :\n");
    printf("dequing element = %d\n",dequeue());
    Traversal(f);



    return 0;
}