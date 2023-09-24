#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Find Min Max
void Min_Max(struct Node *Temp)
{
    int min, max,s_max;
    min = Temp->data;
    max = Temp->data;
    while (Temp != NULL)
    {
        if (min > Temp->data)
        {
            min = Temp->data;
        }
        if (max < Temp->data)
        {
            max = Temp->data;
        }
        Temp = Temp->next;
    }
    
    printf("Maximum No. is = %d \nMinimum No. is = %d", max, min);
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

    Min_Max(Temp);
}
