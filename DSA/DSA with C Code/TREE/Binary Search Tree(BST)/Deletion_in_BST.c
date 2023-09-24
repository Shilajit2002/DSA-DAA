#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left, *right;
};

int val;

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

struct BST *inorderPre(struct BST *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct BST *inorderSuc(struct BST *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct BST *Delete(struct BST *root, int key)
{
    if (root == NULL)
    {
        printf("\n`~`%d is not in the BST `~`", key);
        return NULL;
    }
    else if (key < root->data)
    {
        root->left = Delete(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = Delete(root->right, key);
    }
    else
    {
        // Case 1 and 2 => The Node to be Deleted is a leaf Node or Node has only right Child
        if (root->left == NULL)
        {
            struct BST *temp = root->right;
            free(root);
            if (val == key)
            {
                printf("\n** %d Deleted **", key);
            }
            return temp;
        }
        // Case 1 and 2 => The Node to be Deleted is a leaf Node or Node has only left Child
        else if (root->right == NULL)
        {
            struct BST *temp = root->left;
            free(root);
            if (val == key)
            {
                printf("\n** %d Deleted **", key);
            }
            return temp;
        }
        // Case 3 => The Node to be Deleted has two children using Inorder Predecessor
        struct BST *temp = inorderPre(root->left);
        root->data = temp->data;
        printf("\n** %d Deleted **", key);
        root->left = Delete(root->left, temp->data);

        // Case 3 => The Node to be Deleted has two children using Inorder Successor
        // struct BST* temp=inorderSuc(root->right);
        // root->data=temp->data;
        // printf("\n** %d Deleted **",key);
        // root->right=Delete(root->right,temp->data);

        // For Case 3 we cannot use both process same time..When we use Predecessor then we comment out Successor Code and When we use Successor then we comment out Predecessor Code
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
    int ch, el;
    do
    {
        printf("\n\n1.Insert\n2.In-Order Traversal\n3.Delete\n4.Exit\nEnter your choice = ");
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
                printf("\nIn-Order Traversal = ");
                In_Order(root);
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("\n`~` Tree is Empty`~`");
            }
            else
            {
                printf("\nEnter Element for delete = ");
                scanf("%d", &val);
                root = Delete(root, val);
            }
            break;
        default:
            if (ch != 4)
            {
                printf("\n`~`Invalid Choice`~`");
            }
            break;
        }
    } while (ch != 4);
}