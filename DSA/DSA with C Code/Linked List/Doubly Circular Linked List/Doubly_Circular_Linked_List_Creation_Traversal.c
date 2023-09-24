#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void Traversal(struct Node *Temp)
{
    int count = 0;
    struct Node *Headnode = Temp;

    printf("\n**Elements are : **\n");
    while (Temp->next != Headnode)
    {
        printf("Element %d = %d\n", ++count, Temp->data);
        Temp = Temp->next;
    }
    printf("Element %d = %d\n", ++count, Temp->data);
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
    Temp->next = Headnode;
    Headnode->prev = Temp;
    Temp = Headnode;

    Traversal(Temp);
}