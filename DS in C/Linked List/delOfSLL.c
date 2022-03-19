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
//Case 1 : Delete at the beginning of SLL
struct node * delAtBeg(struct node *head){
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head ;
}

//Case 2 : Deletion In Between of SLL

struct node * delInBet(struct node *head,int index){
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

//Case 3 : Deletion at end of a SLL
struct node * delAtEnd(struct node *head){
    struct node *p = head;
    struct node *q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

//Case 2 : Deletion In Between given value of SLL

struct node * delAtGivValue(struct node *head,int value){
    struct node *p = head;
    struct node *q = head->next;
    while(q->data != value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if (q->data == value)
    {
        p->next=q->next;
        free(q);
    }
    return head;
}

int main()
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

    printf("Linked list before deletion :\n");
    LinkedListTraversal(head);
    //head = delAtBeg(head);    //For deleting first element of the SLL
    //head = delInBet(head,2);
    //head = delAtEnd(head);
    head = delAtGivValue(head,120);
    head = delAtGivValue(head,250);
    printf("\nLinked list after deletion :\n");
    LinkedListTraversal(head);
    return 0;
}