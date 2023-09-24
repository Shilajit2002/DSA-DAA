#include <stdio.h>

int DEQueue[1000];
int front = -1, rear = -1, n, count = 0;

int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == n - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

void enqueue_front()
{
    int el;
    if (isFull())
    {
        printf("\n**DEQueue is Full**");
    }
    else if (front == -1 && rear == -1)
    {
        printf("\nEnter Element = ");
        scanf("%d", &el);
        front = rear = 0;
        DEQueue[front] = el;
        count++;
        printf("\n**Enqueue Front Done**");
    }
    else if (front == 0)
    {
        printf("\nEnter Element = ");
        scanf("%d", &el);
        front = n - 1;
        DEQueue[front] = el;
        count++;
        printf("\n**Enqueue Front Done**");
    }
    else
    {
        printf("\nEnter Element = ");
        scanf("%d", &el);
        front--;
        DEQueue[front] = el;
        count++;
        printf("\n**Enqueue Front Done**");
    }
}

void enqueue_rear()
{
    int el;
    if (isFull())
    {
        printf("\n**DEQueue is Full**");
    }
    else if (front == -1 && rear == -1)
    {
        printf("\nEnter Element = ");
        scanf("%d", &el);
        front = rear = 0;
        DEQueue[rear] = el;
        count++;
        printf("\n**Enqueue Rear Done**");
    }
    else if (rear = n - 1)
    {
        printf("\nEnter Element = ");
        scanf("%d", &el);
        rear = 0;
        DEQueue[rear] = el;
        count++;
        printf("\n**Enqueue Rear Done**");
    }
    else
    {
        printf("\nEnter Element = ");
        scanf("%d", &el);
        rear++;
        DEQueue[rear] = el;
        count++;
        printf("\n**Enqueue Rear Done**");
    }
}

void dequeue_front()
{
    if (isEmpty())
    {
        printf("\n**DEQueue is Empty**");
    }
    else if (front == rear)
    {
        printf("\nDeleted Element is = %d", DEQueue[front]);
        front = rear = -1;
        count--;
        printf("\n**Dequeue Front Done**");
    }
    else if (front == n - 1)
    {
        printf("\nDeleted Element is = %d", DEQueue[front]);
        front = 0;
        count--;
        printf("\n**Dequeue Front Done**");
    }
    else
    {
        printf("\nDeleted Element is = %d", DEQueue[front]);
        front++;
        count--;
        printf("\n**Dequeue Front Done**");
    }
}

void dequeue_rear()
{
    if (isEmpty())
    {
        printf("\n**DEQueue is Empty**");
    }
    else if (front == rear)
    {
        printf("\nDeleted Element is = %d", DEQueue[rear]);
        front = rear = -1;
        count--;
        printf("\n**Dequeue Rear Done**");
    }
    else if (rear == 0)
    {
        printf("\nDeleted Element is = %d", DEQueue[rear]);
        rear = n - 1;
        count--;
        printf("\n**Dequeue Rear Done**");
    }
    else
    {
        printf("\nDeleted Element is = %d", DEQueue[rear]);
        rear--;
        count--;
        printf("\n**Dequeue Rear Done**");
    }
}

void get_front()
{
    if (isEmpty())
    {
        printf("\n**DEQueue is Empty**");
    }
    else
    {
        printf("\nFront Element in The DEQueue is = %d", DEQueue[front]);
    }
}

void get_rear()
{
    if (isEmpty())
    {
        printf("\n**DEQueue is Empty**");
    }
    else
    {
        printf("\nRear Element in The DEQueue is = %d", DEQueue[rear]);
    }
}

void size()
{
    printf("\nTotal Elements in DEQueue are = %d", count);
}

void display()
{
    int i = front;
    if (isEmpty())
    {
        printf("\n**DEQueue is Empty**");
    }
    else
    {
        printf("\nElements in DEQueue are = ");
        while (i != rear)
        {
            printf("%d ", DEQueue[i]);
            i = (i + 1) % n;
        }
        printf("%d ", DEQueue[i]);
    }
}

int main()
{
    printf("Enter Total Size of the Array = ");
    scanf("%d", &n);
    int ch;
    do
    {
        printf("\n1.Enqueue in Front\n2.Enqueue in Rear\n3.Dequeue in Front\n4.Dequeue in Rear\n5.Display\n6.Get Front Element\n7.Get Rear Element\n8.Size\n9.Exit\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue_front();
            break;
        case 2:
            enqueue_rear();
            break;
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            get_front();
            break;
        case 7:
            get_rear();
            break;
        case 8:
            size();
            break;
        default:
            if (ch != 9)
            {
                printf("`~`Invalid Choice`~`");
            }
            break;
        }
    } while (ch != 9);
}