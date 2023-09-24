#include <stdio.h>

#define N 100

int S1[N], S2[N];
int top1 = -1, top2 = -1, count = 0;

int isFull()
{
    if (top1 == N - 1 && top2 == N - 1)
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
    if (top1 == -1 && top2 == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push1(int el)
{
    if (isFull())
    {
        printf("\n**Stack Overflow**");
    }
    else
    {
        // Push the value in Stack1
        top1++;
        S1[top1] = el;
    }
}

void push2(int el)
{
    if (isFull())
    {
        printf("\n**Stack Overflow**");
    }
    else
    {
        // Push the Value in Stack2
        top2++;
        S2[top2] = el;
    }
}

int pop1()
{
    if (isEmpty())
    {
        printf("\n**Stack Underflow**");
    }
    else
    {
        // Pop the value from Stack1
        return S1[top1--];
    }
}

int pop2()
{
    if (isEmpty())
    {
        printf("\n**Stack Underflow**");
    }
    else
    {
        // Pop the value from Stack2
        return S2[top2--];
    }
}

void enqueue()
{
    if (isFull())
    {
        printf("\n**Queue is Full**");
    }
    else
    {
        int el;
        printf("\nEnter the element = ");
        scanf("%d", &el);
        // Push the Element in Stack1
        push1(el);
        printf("\n**Enqueue Done**");
        // Increase Count
        count++;
    }
}

void dequeue()
{
    int i, a, b;
    if (isEmpty())
    {
        printf("\n**Queue is Empty**");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            // Pop the element from Stack1
            a = pop1();
            // Push the element in Stack2
            push2(a);
        }
        // Pop the top element from Stack2
        b = pop2();
        printf("\nThe deleted element is = %d", b);
        // Decrease Count
        count--;
        for (i = 0; i < count; i++)
        {
            // Pop the element from Stack2
            a = pop2();
            // Push the element in Stack1
            push1(a);
        }
        printf("\n**Dequeue Done**");
    }
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
        printf("The elements in the Queue are = ");
        for (i = 0; i <= top1; i++)
        {
            printf("%d ", S1[i]);
        }
    }
}

void size()
{
    printf("The total no elements are = %d", count);
}

void peek()
{
    if (isEmpty())
    {
        printf("\n**Queue is Empty**");
    }
    else
    {
        printf("The Front Element in Queue is = %d", S1[0]);
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