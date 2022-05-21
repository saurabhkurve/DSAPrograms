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

// struct node *search(struct node *root, int data)
// {

//     while (root != NULL)
//     {
//         if (data == root->data)
//         {
//             return root;
//         }
//         else if (data < root->data)
//         {
//             root = root->left;
//         }
//         else
//         {
//             root = root->right;
//         }
//     }
//     return NULL;
// }

void insert(struct node *root, int key)
{
    struct node *prev = NULL;

    while (root != NULL)
    {
        prev = root;   //storing root in prev pointer
        if (key == root->data)
        {
            printf("Cannot insert %d in BST,Already exist in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct node *new = createNode(key);  //creating new node for insrting inton BST

    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
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

    // struct node *sr = search(p, 1);
    // if (sr != NULL)
    // {
    //     printf("Element %d is found in BST", sr->data);
    // }
    // else
    // {
    //     printf("Element is found in Binary tree");
    // }
    // printf("\n");

    insert(p, 7);
    printf("%d inserted in BST", p->right->right->data);
    printf("\n");
    return 0;
}