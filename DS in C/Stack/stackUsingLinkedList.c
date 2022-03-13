#include<stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};



void TraversalSLL(struct Node *ptr){
    while (ptr!= NULL){
        printf("Element = %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top){
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}


int isFull(struct Node *top){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }else{
        return 0;
    }
}

struct Node * push(struct Node *top,int x){
    if(isFull(top)){
        printf("Stack Overflow!\n");
    }else{
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = x;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

struct Node * pop(struct Node *top){
    if(isEmpty(top)){
        printf("Stack underflow!\n");
    
    }else{
        struct Node *temp = top;
        top = (top)->next;
        int x = temp->data;
        free(temp);
        printf("%d popped from the stack\n",x);
        return top;
    }
}

void stackTop(struct Node *ptr){
    printf("Top Most Element is = %d\n",ptr->data);
}

void stackBottom(struct Node *ptr){
    while(ptr->next != NULL){
        ptr= ptr->next;
    }
    printf("Bottom most element is = %d\n",ptr->data);
}

int main()
{
    struct Node *top = NULL;
    top = push(top,34);
    top = push(top,343);
    top = push(top,344);
    top = push(top,345);
    top = push(top,346);
    top = push(top,347);
    top = push(top,348);
    TraversalSLL(top);

    // int element = pop(top);
    // printf("%d element is popped\n",element);

    top = pop(top);
    top = pop(top);

    TraversalSLL(top);

    stackTop(top);
    stackBottom(top);
    return 0;
}