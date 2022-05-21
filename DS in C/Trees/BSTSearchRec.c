#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Creating node for tree
struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

struct node * BSTSearch(struct node *root,int data){
    if(root == NULL){
        return NULL;
    }

    if(data == root->data){
        return root;
    }
    else if(data < root->data){
        return BSTSearch(root->left,data);
    }
    else
    {
        return BSTSearch(root->right,data);
    }
}

int main()
{

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    //       5
    //      / \
    //     3   6
    //    / \   
    //   1  4


    struct node *sr = BSTSearch(p,4);
    if(sr != NULL){
        printf("Element %d is found in BST",sr->data);
    }else{
        printf("Element is found in Binary tree");
    }
    printf("\n");
    return 0;
}