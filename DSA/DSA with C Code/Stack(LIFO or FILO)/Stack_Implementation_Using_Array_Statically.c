#include <stdio.h>

int n, check, arr[1000], top = -1;

int isEmpty()
{
    if (top == -1)
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
    if (top == n - 1)
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
    int el;
    if (isFull())
    {
        printf("\n** Stack Overflow **\n");
    }
    else
    {
        printf("\nEnter Element : ");
        scanf("%d", &el);
        top++;
        arr[top] = el;
        printf("Push Done\n");
    }
}

void pop()
{
    int el;
    if (isEmpty())
    {
        printf("\n** Stack Underflow **\n");
    }
    else
    {
        el = arr[top];
        printf("Deleted Element is = %d",el);
        top--;
        printf("\nPop Done\n");
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
        printf("\nThe Top element in the Stack is : %d\n", arr[top]);
    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\n** Stack is Empty **\n");
    }
    else
    {
        printf("** Elements in the Stack are **\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", arr[i]);
        }
    }
}

void size()
{
    printf("\nTotal Elements are : %d\n", top + 1);
}

int main()
{

    printf("Enter the size of the array : ");
    scanf("%d", &n);

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
