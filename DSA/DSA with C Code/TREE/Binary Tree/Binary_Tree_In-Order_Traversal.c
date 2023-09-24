#include <stdio.h>
#include <stdlib.h>

struct Binary_Tree
{
    int data;
    struct Binary_Tree *left, *right;
};

struct Binary_Tree *create()
{
    int x;
    struct Binary_Tree *newnode;
    newnode = (struct Binary_Tree *)malloc(sizeof(struct Binary_Tree));
    printf("\nEnter Data or Press -1 for no Data = ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    newnode->data = x;
    printf("*\tEnter Left Child of %d\t*", x);
    newnode->left = create();
    printf("*\tEnter Right Child of %d\t*", x);
    newnode->right = create();
    return newnode;
}

void In_Order(struct Binary_Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    In_Order(root->left);
    printf("%d ", root->data);
    In_Order(root->right);
}

void main()
{
    struct Binary_Tree *root;
    root = NULL;
    root = create();
    printf("\n**\tTree is Ready\t**");
    if (root == NULL)
    {
        printf("\nTree is Empty");
    }
    else
    {
        printf("\nIn-Order Traversal => ");
        In_Order(root);
    }
}