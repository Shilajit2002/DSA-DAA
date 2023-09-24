#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Find Occurrence of a given Number
void Occurrence(struct Node *Temp)
{
    int no, count = 0;
    printf("Enter the No. For Finding The Occurrence : ");
    scanf("%d", &no);
    while (Temp != NULL)
    {
        if (no == Temp->data)
        {
            count++;
        }
        Temp = Temp->next;
    }
    if (count == 0)
    {
        printf("Oops! Element is not in the list `~`");
    }
    else
        printf("The Occurrence of %d is %d ", no, count);
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

    Occurrence(Temp);
    int choice;
    do
    {
        printf("\n**Are you want to print another occurrence of a no..**\n1.Yes\n2.No\nEnter Your Choice = ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Occurrence(Temp);
            break;

        default:
            if (choice != 2)
            {
                printf("`~` Invalid Choice..");
            }
            break;
        }
    } while (choice != 2);
}
