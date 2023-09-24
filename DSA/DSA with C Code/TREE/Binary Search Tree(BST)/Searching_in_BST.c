#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left, *right;
};

struct BST *search(struct BST *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

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

void main()
{
    struct BST *root = NULL;
    int ch, key, el;
    do
    {
        printf("\n\n1.Insert\n2.Searching\n3.Exit\nEnter your choice = ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Element = ");
            scanf("%d", &el);
            root = Insert(root, el);
            break;
        case 2:
            if (root == NULL)
            {
                printf("\n`~` Tree is Empty`~`");
            }
            else
            {
                printf("Enter the Searching Element = ");
                scanf("%d", &key);
                struct BST *n = search(root, key);
                if (n != NULL)
                {
                    printf("\n** Found %d **", n->data);
                }
                else
                {
                    printf("\n`~` %d is Not Found in the BST `~`");
                }
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