#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow,cannot push %d element into the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow !)");
        return -1;
    }else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peak(struct stack *ptr,int i){
    int arrayind = ptr->top-i+1;   //gives index at specified position
    if(arrayind<0){
        printf("Invalid position");
        return -1;
    }else{
        return ptr->arr[arrayind];
    }
}
int stackTop(struct stack *ptr){
    if(ptr->top == -1){
        printf("Stack Underflow");
        return -1;
    }else{
        return ptr->arr[ptr->top];
    }
}

int stackBottom(struct stack *ptr){
    if(ptr->top == -1){
        printf("Stack is empty");
        return -1;
    }else{
        return ptr->arr[0];
    }
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int *));


    printf("Stack Empty = %d\n", isEmpty(sp));
    printf("Stack Full = %d\n", isFull(sp));

    push(sp, 5);
    push(sp, 56);
    push(sp, 58);
    push(sp, 59);
    push(sp, 555);
    push(sp, 556);
    push(sp, 5567);
    push(sp, 50000);

    for (int j = 1; j <= sp->top+1; j++)
    {
        printf("Element at position %d is %d\n",j,peak(sp,j));
    }

    printf("This stack contains %d element at the top\n",stackTop(sp));     //returns wich element is at the top of the stack
    printf("This stack contains %d element at the bottom\n",stackBottom(sp));   //returns which element at rhe bottom of the stack
    return 0;
}