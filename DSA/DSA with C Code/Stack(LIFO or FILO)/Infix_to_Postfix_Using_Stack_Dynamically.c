#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Convert
{
    int size;
    int top;
    char *stack;
};

int isEmpty(struct Convert *ptr)
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

int isFull(struct Convert *ptr)
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

void Push(char el,struct Convert *ptr)
{
    
    if (isFull(ptr))
    {
        printf("\n** Stack Overflow **\n");
    }
    else
    {
        ptr->top++;
        ptr->stack[ptr->top] = el;
    }
}

char Pop(struct Convert *ptr)
{
    
    char ele;
    if (isEmpty(ptr))
    {
        printf("\n** Stack Underflow **\n");
    }
    else
    {
        ele = ptr->stack[ptr->top];
        ptr->top--;
        return ele;
    }
}

int Precedence(char ch)
{
    if (ch == '*' || ch == '/' || ch == '%')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '^')
        return 4;
    else
        return 0;
}

int IsOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^' || ch == '%')
    {
        return 1;
    }
    else
        return 0;
}

char *InfixtoPostfix(char P[100])
{
    struct Convert *ptr = (struct Convert *)malloc(sizeof(struct Convert));
    ptr->size = 100;
    ptr->top = -1;

    ptr->stack = (char *)malloc(ptr->size * sizeof(char));
    char *Q = (char *)malloc((strlen(P) + 1) * sizeof(char));

    int i = 0, j = 0;

    while (P[i] != '\0')
    {
        if (P[i] == '(')
        {
            Push(P[i],ptr);
            i++;
        }

        else if (P[i] == ')')
        {
            while (ptr->stack[ptr->top] != '(')
            {
                Q[j] = Pop(ptr);
                j++;
            }
            Pop(ptr);
            i++;
        }

        else if (!IsOperator(P[i]))
        {
            Q[j] = P[i];
            j++;
            i++;
        }
        else
        {
            if (Precedence(P[i]) > Precedence(ptr->stack[ptr->top]))
            {
                Push(P[i],ptr);
                i++;
            }
            else if (P[i] == '^')
            {
                Push(P[i],ptr);
                i++;
            }
            else
            {
                Q[j] = Pop(ptr);
                j++;
            }
        }
    }

    while (!isEmpty(ptr))
    {
        Q[j] = Pop(ptr);
        j++;
    }
    Q[j] = '\0';

    return Q;
}

int main()
{
    char P[100];
    printf("Enter the Infix Expression : ");
    scanf("%s",P);

    printf("Postfix Expression is : %s", InfixtoPostfix(P));
}