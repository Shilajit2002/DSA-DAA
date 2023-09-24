// Checking if a binary tree is a binary search tree or not

#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left, *right;
};

int IsBST(struct BST *root)
{
    static struct BST *prev = NULL;

    if (root != NULL)
    {
        if (!IsBST(root->left))
        {
            return 0;
        }

        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }

        prev = root;
        return (IsBST(root->right));
    }

    else
    {
        return 1;
    }
}

struct BST *create()
{
    int x;
    struct BST *newnode;
    newnode = (struct BST *)malloc(sizeof(struct BST));
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

void main()
{
    struct BST *root;
    root = NULL;
    root = create();
    if (IsBST(root))
    {
        printf("\n** This is Binary Search Tree (BST) **");
    }
    else
    {
        printf("\n`~` This is not a Binary Search Tree (BST) `~`");
    }
}