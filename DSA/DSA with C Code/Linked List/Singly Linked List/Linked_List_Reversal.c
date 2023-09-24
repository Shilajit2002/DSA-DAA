#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *Temp,int length)
{
    printf("\n**Element in Reverse Order **\n");
    while (Temp != NULL)
    {
        printf("Element %d = %d\n", length--, Temp->data);
        Temp = Temp->next;
    }
}

void reverse(struct Node *Temp,int length)
{
    struct Node *Prevnode, *Currentnode, *Nextnode;
    Prevnode = NULL;
    Currentnode = Nextnode = Temp;
    while (Nextnode != NULL)
    {
        Nextnode = Nextnode->next;
        Currentnode->next = Prevnode;
        Prevnode = Currentnode;
        Currentnode = Nextnode;
    }
    Temp = Prevnode;
    Traversal(Temp,length);
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
    Temp->next = NULL;
    Temp = Headnode;

    reverse(Temp,length); 
}