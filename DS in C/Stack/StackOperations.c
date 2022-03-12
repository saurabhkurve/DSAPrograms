#include<stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push (struct stack *ptr,int val){
    if (isFull(ptr)){
        printf("Stack overflow,cannot able to push %d element\n",val);
    }else{
            ptr->top++;
            ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow,Unable to pop an element from the stack");
        return -1;
    }else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size*sizeof(int));

    printf("Before Pushing, %d\n",isEmpty(sp));
    printf("Before Pushing, %d\n",isFull(sp));
    
    push(sp,1);
    push(sp,3);
    push(sp,5);
    push(sp,6);
    push(sp,9);
    push(sp,1);
    push(sp,3);
    push(sp,5);
    push(sp,6);
    push(sp,9);
    push(sp,88); //*Stack Overflow
    
    printf("After Pushing, %d\n",isEmpty(sp));
    printf("After Pushing, %d\n",isFull(sp));

    printf("popped %d from stack\n",pop(sp));
    printf("popped %d from stack\n",pop(sp));

    printf("After Pop Operation, %d\n",isEmpty(sp));
    printf("After Pop Operation, %d\n",isFull(sp));

    //! printf("Stack created succesfully\n");
    return 0;
}