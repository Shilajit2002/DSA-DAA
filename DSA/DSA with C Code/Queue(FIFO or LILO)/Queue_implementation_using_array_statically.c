#include <stdio.h>

int queue[100];
int front = -1, n, rear = -1, count = 0;

// Check Queue is Full or Not
int isFull()
{
    if (rear == n - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Check Queue is Empty or Not
int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Insert an element in the queue
void enqueue()
{
    int el;
    if (isFull())
    {
        printf("\n**Queue is Full**");
    }
    else if (front == -1 && rear == -1)
    {
        printf("\nEnter the element = ");
        scanf("%d", &el);
        rear++, front++;
        queue[rear] = el;
        printf("\n*Enqueue Done*\n");
        count++;
    }
    else
    {
        printf("\nEnter the element = ");
        scanf("%d", &el);
        rear++;
        queue[rear] = el;
        printf("\n*Enqueue Done*");
        count++;
    }
}

// Delete an element from the queue
void dequeue()
{
    int el;
    if (isEmpty())
    {
        printf("\n**Queue is Empty**");
    }
    else if (front == rear)
    {
        el = queue[front];
        printf("\nDeleted Element is = %d", el);
        front = rear = -1;
        printf("\n**Dequeue Done**");
        count = 0;
    }
    else
    {
        el = queue[front];
        printf("\nDeleted Element is = %d", el);
        front++;
        printf("\n**Dequeue Done**");
        count--;
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("\n**Queue is Empty**");
    }
    else
    {
        printf("\nFront element of the queue is = %d", queue[front]);
    }
}

void size()
{
    printf("\nTotal no of elements in the Queue is = %d", count);
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\n**Queue is Empty**");
    }
    else
    {
        printf("\nElement in the Queue are : ");
        for (i = front; i < rear + 1; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    printf("Enter Total Size of the Array = ");
    scanf("%d", &n);
    int ch;
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Size\n6.Exit\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            size();
            break;
        default:
            if (ch != 6)
            {
                printf("`~`Invalid Choice`~`");
            }
            break;
        }
    } while (ch != 6);
}