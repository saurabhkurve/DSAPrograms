#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void LinkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->next;    //Pointing to next node
    }
}

struct node * insertAtBeg(struct node *head,int data){
    struct node  *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next =head;
    ptr->data = data;
    return ptr;
}

struct node * insertInBet(struct node *head,int data,int index){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct node * insertAtEnd(struct node *head,int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next = ptr;
    ptr->data=data;
    ptr->next=NULL;
    return head;
}

int main()head = InsAtBeg(head,40);
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;
    struct node *fifth;
    struct node *sixth;
    struct node *seventh;
    struct node *eight;
    struct node *nine;
    struct node *ten;

    //Allocation of memory of linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    forth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));
    seventh = (struct node *)malloc(sizeof(struct node));
    eight = (struct node *)malloc(sizeof(struct node));
    nine = (struct node *)malloc(sizeof(struct node));
    ten = (struct node *)malloc(sizeof(struct node));

    
    head->data = 7;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 34;
    third->next = forth;

    forth->data = 67;
    forth->next = fifth;

    fifth->data=78;
    fifth->next =sixth;

    sixth->data=89;
    sixth->next=seventh;

    seventh->data=97;
    seventh->next=eight;

    eight->data=120;
    eight->next=nine;

    nine->data=200;
    nine->next=ten;

    ten->data=250;
    ten->next=NULL;

    printf("Linked list before insertion :\n");
    LinkedListTraversal(head);
//  head = insertAtBeg(head,56);
    head = insertInBet(head,43,2);
 //   head = insertAtEnd(head,3444);
    printf("\nLinked list after insertion :\n");
    LinkedListTraversal(head);
    return 0;
}