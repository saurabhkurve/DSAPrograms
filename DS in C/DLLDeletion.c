#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

// Traversing of a DLL
void TraversalDLL(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("List traversed succesfully\n");
}

// Deletion of a node at beginnning of a DLL
struct node *delAtBeg(struct node *head)
{
    struct node *p = head;

    p = p->next;

    free(head);
    head->next = NULL;
    head->prev = NULL;

    p->prev = NULL;
    head = p;
    return head;
}

// Deletion of a node in between of a DLL
struct node *delAtGvnindex(struct node *head, int index)
{
    struct node *q = head;
    struct node *p;
    int i;

    for (i = 1; i <= index - 1; i++)
    {
        p = q;
        q = q->next;
    }

    p->next = q->next;
    q->next->prev = p->next; // or q->prev;

    free(q);
    q->next = NULL;
    q->prev = NULL;

    return head;
}

// Deletion of a node at end of a DLL
struct node *detAtEnd(struct node *head)
{
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->prev->next = NULL;

    free(p);
    p->next = NULL;
    p->prev = NULL;

    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    head->prev = NULL;
    head->data = 12;
    head->next = second;

    second->prev = head;
    second->data = 14;
    second->next = third;

    third->prev = second;
    third->data = 16;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 18;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->data = 20;
    fifth->next = NULL;

    printf("DLL Before insertion :\n");
    TraversalDLL(head);

    // head = delAtBeg(head); // ? Deletion at Beginning

    //head = delAtGvnindex(head, 2); // ? Deletion in between of a DLL

    head = detAtEnd(head);  // ? Deletion at end

    printf("DLL After insertion :\n");
    TraversalDLL(head);

    return 0;
}