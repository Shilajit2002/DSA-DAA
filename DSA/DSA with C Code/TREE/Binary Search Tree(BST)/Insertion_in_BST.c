#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left, *right;
};

struct BST *Insert(struct BST *root, int key)
{
    if (root == NULL)
    {
        root = (struct BST *)malloc(sizeof(struct BST));
        root->data = key;
        root->left = root->right = NULL;
        printf("\n** %d Inserted **", root->data);
        return root;
    }
    else if (key < root->data)
    {
        root->left = Insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = Insert(root->right, key);
    }
    else
    {
        printf("\n%d is already in BST", key);
    }
    return root;
}

void In_Order(struct BST *root)
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
    struct BST *root = NULL;
    int ch, key;
    do
    {
        printf("\n\n1.Insert\n2.In-Order Traversal\n3.Exit\nEnter your choice = ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Element = ");
            scanf("%d", &key);
            root = Insert(root, key);
            break;
        case 2:
            if (root == NULL)
            {
                printf("\n`~` Tree is Empty`~`");
            }
            else
            {
                printf("\nIn-Order Traversal = ");
                In_Order(root);
            }
            break;
        default:
            if (ch != 3)
            {
                printf("\n`~`Invalid Choice`~`");
            }
            break;
        }
    } while (ch != 3);
}