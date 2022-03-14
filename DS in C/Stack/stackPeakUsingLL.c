#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void TraversalSLL(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = x;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

struct Node *pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack underflow!\n");
    }
    else
    {
        struct Node *temp = top;
        top = (top)->next;
        int x = temp->data;
        free(temp);
        printf("%d popped from the stack\n", x);
        return top;
    }
}

void stackTop(struct Node *ptr)
{
    printf("Top Most Element is = %d\n", ptr->data);
}

void stackBottom(struct Node *ptr)
{
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    printf("Bottom most element is = %d\n", ptr->data);
}

int peak(struct Node *top, int pos)
{ // From Position 1
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int peak1(struct Node *top, int pos1)
{ // From position 0
    struct Node *ptr1 = top;
    for (int i = 0; (i < pos1 && ptr1 != NULL); i++)
    {
        ptr1 = ptr1->next;
    }
    if (ptr1 != NULL)
    {
        return ptr1->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    struct Node *top = NULL;

    top = push(top, 34);
    top = push(top, 343);
    top = push(top, 344);
    top = push(top, 345);
    top = push(top, 346);
    top = push(top, 347);
    top = push(top, 348);

    TraversalSLL(top);

    stackTop(top);
    stackBottom(top);

    // printf("Value at position 1 is = %d\n",peak(1));

    for (int i = 1; i <= 7; i++)
    {
        printf("Value at position %d is = %d\n", i, peak(top, i));
    }

    for (int k = 0; k < 7; k++)
    {
        printf("value at position %d is = %d\n", k, peak(top, k));
    }
    return 0;
}