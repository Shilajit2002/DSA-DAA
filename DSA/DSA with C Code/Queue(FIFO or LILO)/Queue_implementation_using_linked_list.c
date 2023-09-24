#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *front = NULL;
struct Queue *rear = NULL;
int count = 0;

// Check Queue is Full or Not
int isFull()
{
    struct Queue *p = (struct Queue *)malloc(sizeof(struct Queue));
    if (p == NULL)
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
    if (front == NULL && rear == NULL)
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
    else if (front == NULL && rear == NULL)
    {
        struct Queue *currentnode;
        currentnode = (struct Queue *)malloc(sizeof(struct Queue));
        printf("\nEnter Element = ");
        scanf("%d", &currentnode->data);
        currentnode->next = NULL;
        front = rear = currentnode;
        count++;
    }
    else
    {
        struct Queue *currentnode;
        currentnode = (struct Queue *)malloc(sizeof(struct Queue));
        printf("\nEnter Element = ");
        scanf("%d", &currentnode->data);
        currentnode->next = NULL;
        rear->next = currentnode;
        rear = currentnode;
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
        struct Queue *temp = front;
        el = front->data;
        printf("\nDeleted Element is = %d", el);
        front = rear = NULL;
        free(temp);
        printf("\n**Dequeue Done**");
        count = 0;
    }
    else
    {
        struct Queue *temp = front;
        el = front->data;
        printf("\nDeleted Element is = %d", el);
        front = front->next;
        free(temp);
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
        printf("\nFront element of the queue is = %d", front->data);
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
        struct Queue *temp = front;
        printf("\nElement in the Queue are : ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
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