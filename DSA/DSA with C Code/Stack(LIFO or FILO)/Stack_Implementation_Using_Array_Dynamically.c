// Stack Using Array Dynamically

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *ptr)
{
    int el;
    if (isFull(ptr))
    {
        printf("\n** Stack Overflow **\n");
    }
    else
    {
        printf("\nEnter Element : ");
        scanf("%d", &el);
        ptr->top++;
        ptr->arr[ptr->top] = el;
        printf("Push Done\n");
    }
}

void pop(struct Stack *ptr)
{
    int el;
    if (isEmpty(ptr))
    {
        printf("\n** Stack Underflow **\n");
    }
    else
    {
        el = ptr->arr[ptr->top];
        ptr->top--;
        printf("Pop Done\n");
    }
}

void peek(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\n** Stack is Empty **\n");
    }
    else
    {
        printf("\nThe Top element in the Stack is : %d\n", ptr->arr[ptr->top]);
    }
}

void display(struct Stack *ptr)
{
    int i;
    if (isEmpty(ptr))
    {
        printf("\n** Stack is Empty **\n");
    }
    else
    {
        printf("** Elements in the Stack are **\n");
        for (i = ptr->top; i >= 0; i--)
        {
            printf("%d\n", ptr->arr[i]);
        }
    }
}

void size(struct Stack *ptr)
{
    printf("\nTotal Elements are : %d\n", (ptr->top)+1);
}

int main()
{
    struct Stack *ptr = (struct Stack *)malloc(sizeof(struct Stack));

    printf("Enter the size of the array : ");
    scanf("%d", &ptr->size);
    ptr->top = -1;
    ptr->arr = (int *)malloc(ptr->size * sizeof(int));

    int check;
    do
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Size or Total Elements\n6.Quit\nChoose Your Option : ");
        scanf("%d", &check);
        switch (check)
        {
        case 1:
            push(ptr);
            break;
        case 2:
            pop(ptr);
            break;
        case 3:
            peek(ptr);
            break;
        case 4:
            display(ptr);
            break;
            case 5:
            size(ptr);
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