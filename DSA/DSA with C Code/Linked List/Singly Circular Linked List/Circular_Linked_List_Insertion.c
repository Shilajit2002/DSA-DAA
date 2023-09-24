#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversal
void Traversal(struct Node *Temp)
{
    struct Node *ptr = Temp;
    int count = 0;
    printf("\n**Elements are : **\n");
    while (ptr->next != Temp)
    {
        printf("Element %d = %d\n", ++count, ptr->data);
        ptr = ptr->next;
    }
    printf("Element %d = %d\n", ++count, ptr->data);
}

// Insert at the Beginning
void InsertAtFirst(struct Node **Temp)
{
    int data;

    printf("\nEnter the Inserting Element : ");
    scanf("%d", &data);

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p;

    ptr->data = data;

    // Main Logic
    if (*Temp == NULL)
    {
        *Temp = ptr;
        ptr->next = *Temp;
    }
    else
    {
        p = *Temp;
        while (p->next != *Temp)
        {
            p = p->next;
        }
        ptr->next = *Temp;
        p->next = ptr;
        *Temp = ptr;
    }

    Traversal(*Temp);
}

// Insert at the End
void InsertAtEnd(struct Node **Temp)
{
    int data;

    printf("\nEnter the Inserting Element : ");
    scanf("%d", &data);

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    // Main Logic
    ptr->data = data;

    if (*Temp == NULL)
    {
        *Temp = ptr;
        ptr->next = *Temp;
    }
    else
    {
        struct Node *p = *Temp;
        while (p->next != *Temp)
        {
            p = p->next;
        }

        p->next = ptr;
        ptr->next = *Temp;
    }
    Traversal(*Temp);
}

// Insert at a particular Index
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

        // Main Logic
        int j = 1;
        while (j < index - 1)
        {
            p = p->next;
            j++;
        }
        printf("\nEnter the Inserting Element : ");
        scanf("%d", &data);

        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;
        
        Traversal(*Temp);
    }
    
}

int main()
{
    int length, i;
    printf("Enter the total numbers : ");
    scanf("%d", &length);

    struct Node *Headnode, *Currentnode, *Temp;

    for (i = 0; i < length; i++)
    {
        Currentnode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the %d Element : ", i + 1);
        scanf("%d", &Currentnode->data);

        if (i == 0)
        {
            Headnode = Temp = Currentnode;
        }
        else
        {
            Temp->next = Currentnode;
            Temp = Currentnode;
        }
    }
    Temp->next = Headnode;
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