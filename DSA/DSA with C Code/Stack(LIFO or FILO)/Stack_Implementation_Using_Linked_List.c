#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *Top = NULL;
int count = 0;

int isEmpty()
{
    if (Top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    // When Heap memory will be exhausted
    struct Stack *p = (struct Stack *)malloc(sizeof(struct Stack));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push()
{
    if (isFull())
    {
        printf("\n** Stack Overflow **\n");
    }
    else
    {
        struct Stack *el = (struct Stack *)malloc(sizeof(struct Stack));
        printf("\nEnter Element : ");
        scanf("%d", &el->data);
        el->next = Top;
        Top = el;
        printf("Push Done\n");
        count++;
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("\n** Stack Underflow **\n");
    }
    else
    {
        struct Stack *Temp = Top;
        Top = Top->next;
        free(Temp);
        printf("Pop Done\n");
        count--;
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("\n** Stack is Empty **\n");
    }
    else
    {
        printf("\nThe Top element in the Stack is : %d\n", Top->data);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\n** Stack is Empty **\n");
    }
    else
    {
        struct Stack *Temp=Top;
        printf("** Elements in the Stack are **\n");
        while (Temp != NULL)
        {
            printf("%d\n", Temp->data);
            Temp = Temp->next;
        }
    }
}

void size()
{
    printf("\nTotal Elements are : %d\n", count);
}

int main()
{
    int check;
    do
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Size or Total Elements\n6.Quit\nChoose Your Option : ");
        scanf("%d", &check);
        switch (check)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            size();
            break;
        default:
            if (check != 6)
            {
                printf("\n`~` Invalid Choice `~`\n");
                break;
            }
        }
    } while (check != 6);
}