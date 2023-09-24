#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Traversal
void Traversal(struct Node *Temp, int length)
{
    printf("\n** Reverse Order of Doubly Linked List **\n");
    while (Temp != NULL)
    {
        printf("Element %d = %d\n", length--, Temp->data);
        Temp = Temp->next;
    }
}

// Reverse Order
void Reverse(struct Node *Temp, struct Node *Tail, int length)
{
    struct Node *Currentnode, *Nextnode;
    Currentnode = Temp;
    while (Currentnode != NULL)
    {
        Nextnode = Currentnode->next;
        Currentnode->next = Currentnode->prev;
        Currentnode->prev = Nextnode;
        Currentnode = Nextnode;
    }
    Currentnode = Temp;
    Temp = Tail;
    Tail = Currentnode;

    Traversal(Temp, length);
}

int main()
{
    int length, i;
    printf("Enter the total numbers : ");
    scanf("%d", &length);

    struct Node *Headnode, *Tail, *Currentnode, *Temp;

    // Creating The Doubly Linked List
    for (i = 0; i < length; i++)
    {
        Currentnode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the %d Element : ", i + 1);
        scanf("%d", &Currentnode->data);
        Currentnode->next = NULL;
        Currentnode->prev = NULL;

        if (i == 0)
        {
            Headnode = Temp = Currentnode;
        }
        else
        {
            Temp->next = Currentnode;
            Currentnode->prev = Temp;
            Temp = Currentnode;
        }
    }
    Tail = Temp;
    Temp = Headnode;

    Reverse(Temp, Tail, length);
}