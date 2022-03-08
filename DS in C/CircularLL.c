#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void CLTraversal(struct node *head){
    struct node *ptr = head;
    do{
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

//Inserting at Beginning of a linked list
struct node * InsAtBeg(struct node *head,int data){
    struct node *ptr = (struct node *) malloc (sizeof(struct node));
    ptr->data=data;
    struct node *p = head->next;

    while (p->next != head)
    {
        p=p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
struct node * InsInBet(struct node *head,int data,int index){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = data;
    int i;
    for(i = 0 ;i < index-1;i++)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node * InsAtEnd(struct node *head,int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;

    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
     
    head->data = 4;
    head->next=second;
    
    second->data= 7;
    second->next= third;

    third->data= 12;
    third->next= fourth;

    fourth->data= 20;
    fourth->next = head;

    printf("Circular Linked List Before insertion\n");
    CLTraversal(head);

    //head = InsAtBeg(head,40); //Inserting at begining of a CLL
    //head = InsInBet(head,60,2);  //Inserting at given index
    head = InsAtEnd(head,500);
    printf("Circular Linked List After insertion\n");
    CLTraversal(head);
    return 0;
}