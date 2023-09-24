#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    char *arr;
};

// Check the stack is Full or Not
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

// Check the stack is Empty or Not
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

// Push the Open Parentheses into the stack
void push(struct Stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("*Stack Overflow*");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// Pop the Open Parentheses from the stack
void pop(struct Stack *ptr)
{
    char val;
    if (isEmpty(ptr))
    {
        printf("*Stack Underflow*");
    }
    else
    {
        val = ptr->arr[ptr->top];
        ptr->top--;
    }
}

// Parentheses Matching Function
int Parenthesesmatch(char num[1000])
{
    struct Stack *ptr = (struct Stack *)malloc(sizeof(struct Stack));
    ptr->size = 1000;
    ptr->top = -1;
    ptr->arr = (char *)malloc(ptr->size * sizeof(char)); //Alocate the memory for stack

    int i;
    for (i = 0; num[i] != '\0'; i++)
    {
        if (num[i] == '(')
        {
            push(ptr, '('); // Push open Parentheses into the stack
        }
        else if (num[i] == ')')
        {
            if (isEmpty(ptr))
            {
                return 0; // Check if the stack is empty then return 0 and close the programm
            }
            else
            {
                pop(ptr); // Check if the stack is full by only one open parentheses or more than one parentheses then simply pop the  one open parentheses from the stack
            }
        }
    }
    if (isEmpty(ptr))
    {
        return 1; // Check if the stack is empty then return 1 and close the programm
    }
    else
    {
        return 0; // Check if the stack is not empty then return 0 and close the programm
    }
}

int main()
{
    char num[10000];
    printf("Enter the expression : ");
    scanf("%s", num);
    if (Parenthesesmatch(num)) // If return 1 Parentheses is match
    {
        printf("**The Parentheses is Matching**");
    }
    else // Else return 0 Parentheses is not match
    {
        printf("`~`The Parentheses is not Matching`~`");
    }
}