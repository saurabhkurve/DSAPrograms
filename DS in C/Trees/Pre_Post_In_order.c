#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};


//Creating node for tree
struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}


//Preorder TraversalDLL
void preOrder(struct node *root){

    if(root != NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//Postorder TraversalDLL
void postOrder(struct node *root){

    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

//Inorder TraversalDLL
void inOrder(struct node *root){

    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main(){

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right =p4;

    //       4
    //      / \
    //     1   6
    //    / \   
    //   5  2 

    printf("Preorder Traversal \n");
    preOrder(p);
    printf("\n");

    printf("Postorder Traversal \n");
    postOrder(p);
    printf("\n");

    printf("Inorder Traversal \n");
    inOrder(p);
    printf("\n");
    return 0;
}