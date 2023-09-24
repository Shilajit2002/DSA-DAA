#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversal
int Traversal(struct Node *Temp)
{
    struct Node *ptr = Temp;
    int count = 0;
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        printf("\n**Elements are : **\n");
        while (ptr->next != Temp)
        {
            printf("Element %d = %d\n", ++count, ptr->data);
            ptr = ptr->next;
        }
        printf("Element %d = %d\n", ++count, ptr->data);
    }
}

// Delete at the Beginning
void DeleteAtFirst(struct Node **Temp)
{
    struct Node *p;
    if ((*Temp)->next == *Temp)
    {
        p = *Temp;
        *Temp = NULL;
        free(p);
        printf("*List is Empty*");
    }
    else
    {
        p = *Temp;
        while (p->next != *Temp)
        {
            p = p->next;
        }
        p->next = (*Temp)->next;
        p = *Temp;
        *Temp = (*Temp)->next;
        free(p);
    }

    Traversal(*Temp);
}

// Delete at the End
void DeleteAtEnd(struct Node **Temp)
{
    // Main Logic
    struct Node *p = *Temp;
    struct Node *q = (*Temp)->next;
    if ((*Temp)->next == *Temp)
    {
        *Temp = NULL;
        free(p);
        printf("*List is Empty*");
    }
    else
    {
        while (q->next != *Temp)
        {
            p = p->next;
            q = q->next;
        }
        p->next = *Temp;
        free(q);
    }
    Traversal(*Temp);
}

// Delete at a particular Index
void DeleteAtIndex(struct Node **Temp)
{
    int index;
    printf("\nEnter the Deleting Position : ");
    scanf("%d", &index);
    struct Node *p = *Temp;
    struct Node *q = (*Temp)->next;
    
    if (index == 1)
    {
        DeleteAtFirst(Temp);
    }
    else if ((*Temp)->next == *Temp)
    {
        *Temp = NULL;
        free(p);
        printf("*List is Empty*");
    }
    else
    {
        // Main Logic
        int j = 1;
        while (j < index - 1)
        {
            p = p->next;
            q = q->next;
            j++;
        }
        p->next = q->next;
        free(q);

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