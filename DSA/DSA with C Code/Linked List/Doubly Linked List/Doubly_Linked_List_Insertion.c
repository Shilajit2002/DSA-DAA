#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Traversal
void Traversal(struct Node *Temp)
{
    int count = 0;
    printf("\n**Elements are : **\n");
    while (Temp != NULL)
    {
        printf("Element %d = %d\n", ++count, Temp->data);
        Temp = Temp->next;
    }
}

// Insertion At Beginning
void InsertAtFirst(struct Node **Temp)
{
    int data;

    printf("\nEnter the Inserting Element : ");
    scanf("%d", &data);

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->prev = NULL;

    (*Temp)->prev = ptr; // MAIN
    ptr->next = *Temp;
    *Temp = ptr; //Logic

    Traversal(*Temp);
}

// Insert At End
void InsertAtEnd(struct Node **Temp)
{
    int data;

    printf("\nEnter the Inserting Element : ");
    scanf("%d", &data);

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = NULL;

    struct Node *p = *Temp; // MAIN

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;
    p = ptr; // Logic

    Traversal(*Temp);
}

// Insert At Particular Position
void InsertAtIndex(struct Node **Temp)
{
    int data, index;

    printf("\nEnter the Inserting Position : ");
    scanf("%d", &index);

    if (index == 1)
    {
        InsertAtFirst(Temp);
    }

    else
    {

        struct Node *p = *Temp;

        int j = 1; //MAIN
        while (j < index - 1)
        {
            p = p->next;
            j++;
        }
        printf("\nEnter the Inserting Element : ");
        scanf("%d", &data);

        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;
        ptr->prev = NULL;

        ptr->prev = p;
        ptr->next = p->next;
        p->next = ptr;
        ptr->next->prev = ptr; //Logic

        Traversal(*Temp);
    }
}

int main()
{
    int length, i;
    printf("Enter the total numbers : ");
    scanf("%d", &length);

    struct Node *Headnode, *Currentnode, *Temp;

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
    Temp = Headnode;

    int check;

    // Performing The Insertion Operation
    do
    {
        printf("\n1.Insert At Beginning\n2.Insert At End\n3.Insert At a Particular Position\n4.Quit\n**Choose Your Option** : ");
        scanf("%d", &check);
        switch (check)
        {
        case 1:
            InsertAtFirst(&Temp);
            break;
        case 2:
            InsertAtEnd(&Temp);
            break;
        case 3:
            InsertAtIndex(&Temp);
            break;

        default:
            if (check != 4)
            {
                printf("\nInvalid Choice`~`\n");
            }
            break;
        }

    } while (check != 4);
}