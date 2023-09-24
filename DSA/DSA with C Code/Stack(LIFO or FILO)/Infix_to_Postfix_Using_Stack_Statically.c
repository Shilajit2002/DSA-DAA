#include <stdio.h>

int top = -1;                    // Set top value to the Stack
char P[100], Q[100], stack[100]; //  Set the Array and Stack size
int i = 0, j = 0;

// IsEmpty Function for checking the stack is empty or not
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

// IsFull Function for checking the stack is full or not
int isFull()
{
    if (top == 100 - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Push the array operators into the stack
void Push(char el)
{
    if (isFull())
    {
        printf("\n** Stack Overflow **\n");
    }
    else
    {
        top++;
        stack[top] = el;
    }
}

// Pop the array operators from the stack
char Pop()
{
    char ele;
    if (isEmpty())
    {
        printf("\n** Stack Underflow **\n");
    }
    else
    {
        ele = stack[top];
        top--;
        return ele;
    }
}

// Check the Precedence of Operators
int Precedence(char ch)
{
    if (ch == '*' || ch == '/' || ch == '%')
        return 3; // This Precedence is 3 so less higher
    else if (ch == '+' || ch == '-')
        return 2; // This Precedence is 2 so lower
    else if (ch == '^')
        return 4; // This Precedence is 4 so much higher
    else
        return 0;
}

// Check the array element is Operator or not
int IsOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^' || ch == '%')
    {
        return 1; // Is operator return 1
    }
    else
        return 0; // Isnot operator return 0
}

//  Convert Infix to Postfix
char *InfixtoPostfix(char P[100])
{
    // Until the array becomes end
    while (P[i] != '\0')
    {
        // If Open Parentheses (
        if (P[i] == '(')
        {
            Push(P[i]); // Push this into the stack
            i++;
        }

        // If Closing Parentheses )
        else if (P[i] == ')')
        {
            // Until stack top reach Open Parentheses (
            while (stack[top] != '(')
            {
                Q[j] = Pop(stack[top]); // Pop the Operators from the stack and push it into the array
                j++;
            }
            Pop(stack[top]); // Then Pop Open Parentheses from the stack
            i++;
        }

        // If it is not Operator
        else if (!IsOperator(P[i]))
        {
            Q[j] = P[i]; // Push the character into the array
            j++;
            i++;
        }
        else
        {
            // If Higher Precendence than the top element
            if (Precedence(P[i]) > Precedence(stack[top]))
            {
                Push(P[i]); // Push the operator into the stack
                i++;
            }

            // If Precendence is same but associativity is right - left (Power '^' Operator)
            else if (P[i] == '^')
            {
                Push(P[i]); // Push the operator into the stack
                i++;
            }

            // If Lower Precendence than the top element or If Precendence is same but associativity is left - right (Another Operators)
            else
            {
                Q[j] = Pop(stack[top]); // Pop the operator from the stack and push into the array
                j++;
            }
        }
    }

    // If stack in not Empty
    while (!isEmpty(stack))
    {
        Q[j] = Pop(stack[top]); // Pop all the element from the stack and push into the array
        j++;
    }

    // Set NULL of the last element of the array
    Q[j] = '\0';
    return Q; // Return the Postfix Expression
}

int main()
{
    printf("Enter the Infix Expression : ");
    scanf("%s", P);
    printf("Postfix Expression is : %s", InfixtoPostfix(P));
}