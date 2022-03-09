#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

//Traversing of a DLL
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

//Reverse traversing of doubly linked list
void TraverseRev(struct node *head){
    struct node *p = head;
    //struct node *temp;
    while(p->next !=NULL){
        p = p->next;
    }

    while(p != NULL){
        printf("%d\n",p->data);
        p = p->prev;
    }
    printf("List traversed reversely\n");
}

//Insert a node at beginnning of a DLL
struct node * insAtBeg(struct node *head,int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    
    ptr->data = data;
    ptr->next = head;
    head->prev = ptr;
    ptr->prev = NULL;
    head = ptr;
    return head;
}

//Insert in between of a DLL
struct node * insInBet(struct node *head,int data,int index){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    struct node *temp = head->next;
    int i;
    for(i = 1;i < index-1 ; i++){
        p = p->next;
        temp = temp->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = temp;
    temp->prev = ptr;
    ptr->prev = p; 
    return head;
}

//Insert a node to a DLL at end
struct node * insAtEnd(struct node *head,int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    while(p->next != NULL){
        p = p->next;
    }

    ptr->data = data;
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;
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
    //TraverseRev(head);

    //head = insAtBeg(head,10);
    //head = insInBet(head,15,3);
    head = insAtEnd(head,25);
    printf("DLL After insertion :\n");
    TraversalDLL(head);
    return 0;
}