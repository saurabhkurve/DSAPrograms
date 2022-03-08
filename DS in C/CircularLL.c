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

    head = InsAtBeg(head,40); //Inserting at begining of a CLL
    head = InsAtBeg(head,40);
    printf("Circular Linked List After insertion\n");
    CLTraversal(head);
    return 0;
}