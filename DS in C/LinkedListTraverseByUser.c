#include <stdio.h>
#include <stdlib.h>
// void traverseList(struct Node *);
// void createList(int);
struct Node
{
    int data;
    struct Node *next;
} * head;

void createList(int n)
{
    struct Node *newNode, *temp;
    int data, i;

    head = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        printf("Unable to allocate mamory ");
        exit(0);
    }
    else
    {
        printf("Enter the data of node 1 :");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        temp = head;
        for (i = 2; i <= n; i++)
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            if (newNode == NULL)
            {
                printf("Unable to allocate memory ");
                break;
            }
            else
            {
                printf("Enter the data of node %d:", i);
                scanf("%d", &data);

                newNode->data = data;
                newNode->next = NULL;

                temp->next = newNode;
                temp = temp->next;
            }
        }
        printf("Singly Linked list created succesfully");
    }
}

//Insert Node at beginning SLL
void insertAtBeg(int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory");
    }
    else
    {
        newNode->data = data;
        newNode->next = head;
        head = newNode;

        printf("Data inserted successfully\n");
    }
}

void traverseList()
{
    struct Node *temp;

    // Return if list is empty
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }

    temp = head;
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data); // Print data of current node
        temp = temp->next;                 // Move to next node
    }
}

void insertInBetween(int data,int index){
    struct Node *newNode,*temp;
    int i;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Unable to allocate memory");
    }   
    else{
            newNode->data = data;
            newNode->next = NULL;

            temp = head;

            for ( i = 2; i <= index-1; i++)  //treaversing linked list till we find position
            {
                temp = temp->next;

                if(temp == NULL){
                    break ;
                }
            }

            if(temp != NULL){
                newNode->next = temp->next;

                temp->next = newNode;
            }
            
    }
}

void insertAtEnd (int data){
    struct Node *newNode,*temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Unable to allocate memory ");
    }
    else{
        newNode->data =data;
        newNode->next =NULL;

        temp = head;

        while (temp != NULL && temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = newNode;
    }

}
int main()
{
    int n, data,index;

    printf("Enter the total number of nodes :");
    scanf("%d", &n);

    createList(n);
    printf("Data in list is \n");
    traverseList();
    // printf("Insert data to be inserted in new node of a list:");
    // scanf("%d", &data);

    //insertAtBeg(data);

    printf("Insert data to be inserted in new node of a list:");
    scanf("%d", &data);
    printf("Enter the index at which you wish to insert a node :");
    scanf("%d",&index);
    
     insertInBetween(data,index);

    //printf("Insert data to be inserted in new node of a list:");
    //scanf("%d", &data);

    //insertAtEnd(data);
    printf("\nAfter insertion : \n");
    traverseList();
    return 0;
}