#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversal
void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *Head;
    struct Node *Second;
    struct Node *Third;
    struct Node *Fourth;

    // Allocate memory for nodes in the linked list in Heap
    Head = (struct Node *)malloc(sizeof(struct Node));
    Second = (struct Node *)malloc(sizeof(struct Node));
    Third = (struct Node *)malloc(sizeof(struct Node));
    Fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second node
    Head->data = 14;
    Head->next = Second;

    // Link second and third node
    Second->data = 50;
    Second->next = Third;

    // Link third and fourth node
    Third->data = 78;
    Third->next = Fourth;

    // Link fourth and null node
    Fourth->data = 100;
    Fourth->next = NULL;

    linkedlisttraversal(Head);
}
