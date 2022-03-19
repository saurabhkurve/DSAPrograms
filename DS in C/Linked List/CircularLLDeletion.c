#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void CLTraversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Deletion at beginning of CLL
struct node *DelAtBeg(struct node *head)
{
    struct node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    free(head);
    head = p->next;
    return head;
}

struct node *DelAtGivVal(struct node *head, int value)
{
    struct node *p, *q;
    p = head;

    while (p->data != value)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
    p = NULL;
    return head;
}

struct node *DelAtEnd(struct node *head)
{
    struct node *p, *q;
    p = head;

    while (p->next != head)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
    p = NULL;
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 4;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = head;

    printf("Circular Linked List Before deletion\n");
    CLTraversal(head);

    // head = DelAtBeg(head); //Deletion at Beginning
    //  head = DelAtGivVal(head,7);  //(head,value) deletion of a node with given value

    head = DelAtEnd(head); //(head,value) deletion of a node with given value

    printf("Circular Linked List After deletion\n");
    CLTraversal(head);
    return 0;
}