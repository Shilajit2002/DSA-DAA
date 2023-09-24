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
    while (Temp != NULL)
    {
        printf("Element %d = %d\n", ++count, Temp->data);
        Temp = Temp->next;
    }
    printf("Total no of element is : %d\n", count);
}

// Delete at the Beginning
void DeleteAtFirst(struct Node **Temp)
{
    struct Node *ptr = *Temp; //MAIN
    *Temp = (*Temp)->next;
    (*Temp)->prev = NULL;
    free(ptr); //LOGIC

    Traversal(*Temp);
}

// Delete at the End
void DeleteAtEnd(struct Node **Temp)
{
    struct Node *ptr = *Temp;
    while (ptr->next != NULL) //MAIN
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr); //LOGIC

    Traversal(*Temp);
}

// Delete at a particular Index
void DeleteAtIndex(struct Node **Temp)
{
    int index;
    printf("\nEnter the Deleting Position : ");
    scanf("%d", &index);
    if (index == 1) //MAIN
    {
        DeleteAtFirst(Temp);
    }
    else
    {
        struct Node *ptr = *Temp;

        int j = 1;
        while (j < index)
        {
            ptr = ptr->next;
            j++;
        }
        if (ptr->next == NULL)
        {
            DeleteAtEnd(Temp);
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);

            Traversal(*Temp);
        }
    } //LOGIC
}

int main()
{
    int length, i;
    printf("Enter the total numbers : ");
    scanf("%d", &length);

    struct Node *Headnode, *Currentnode, *Temp, *Tail;

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

    int check;
    // Performing The Deletion Operation
    do
    {
        printf("\n1.Delete At Beginning\n2.Delete At End\n3.Delete At a Particular Position\n4.Quit\n**Choose Your Option** : ");
        scanf("%d", &check);
        switch (check)
        {
        case 1:
            DeleteAtFirst(&Temp);
            break;
        case 2:
            DeleteAtEnd(&Temp);
            break;
        case 3:
            DeleteAtIndex(&Temp);
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