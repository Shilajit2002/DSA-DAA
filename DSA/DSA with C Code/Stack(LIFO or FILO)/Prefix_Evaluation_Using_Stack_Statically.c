#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Set the Value of variables
int top = -1;
double stack[100];
int i, rev=10,space = 0;
double end;

// Check Stack is Empty or Not
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

// Check Stack is Full or Not
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

// This is Displsy function of stack..if you want to see how the stack would work ..then simply uncomment the below code and check...also uncomment display() this line in below

// void dispaly()
// {
//     int k;
//     printf("Stack =>");
//     for (k = 0; k <= top; k++)
//     {
//         printf(" | %.2lf", stack[k]);
//     }
//     printf("\n");
// }

// Pop element from stack
double Pop()
{
    double ele;
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        ele = stack[top];
        top--;
        return ele;
    }
}

// Push element into stack
int Push(double el)
{
    if (isFull())
    {
        return 0;
    }
    else
    {
        // if no space between two numbers then
        if (space == 1)
        {
            double num1,num2;
            num1 = Pop();                  // pop the previous number
            num2 = num1 + rev * el;
            rev=rev*10;
            stack[++top]=num2;
        }
        // if space between two numbers then
        else if (space == 0)
        {
            rev=10;
            stack[++top] = el; //push the number into stack
            space = 1;
        }
    }
}

// Prefix evaluation function
int PrefixEvaluation(char P[100])
{
    double n1, n2, n3, num;
    int n4, n5, n6;
    // set i value of Expression P length -1
    i = strlen(P) - 1;
    // until expression reached start position
    while (i >= 0)
    {
        // if element is digit
        if (isdigit(P[i]))
        {
            num = P[i] - 48; // Convert it into digit
            Push(num);       // Push into the stack
        }
        // if element is space
        else if (P[i] == ' ')
        {
            space = 0; // set space value = 0
        }
        // if element is any operator
        else
        {
            n1 = Pop(); // Pop the frist number from the stack
            n2 = Pop(); // Pop the second number from the stack

            switch (P[i])
            {
            // elemnt is + operator
            case '+':
            {
                n3 = n1 + n2; // then add two number
                break;
            }
            // elemnt is - operator
            case '-':
            {
                n3 = n1 - n2; // then substract two number
                break;
            }
            // elemnt is * operator
            case '*':
            {
                n3 = n1 * n2; // then multiply two number
                break;
            }
            // elemnt is / operator
            case '/':
            {
                n3 = n1 / n2; // then divide two number
                break;
            }
            // elemnt is % operator
            case '%':
            {
                n6 = n2, n5 = n1;
                n4 = n5 % n6; // then modulus two number
                break;
            }
            // elemnt is ^ operator
            case '^':
            {
                n3 = pow(n1, n2); // then n2 to the power n1
                break;
            }
            // if not match the operator return 0
            default:
                return 0;
            }

            // if % operator
            if (P[i] == '%')
                Push(n4); // Push the number into the stack
            else
                Push(n3); // if another operator
        }
        i--;
        // dispaly();
    }
    end = Pop(); // Pop the element from the stack when the expression will end

    // if stack empty
    if (isEmpty())
    {
        return 1; // return 1
    }
    else
    {
        return 0; // if stack not empty return 0
    }
}
int main()
{
    char P[100];
    printf("Enter the Prefix Expression : ");
    gets(P);
    if (PrefixEvaluation(P))
    {
        printf("Prefix Evaluation is : %.0lf", end);
    }
    else
    {
        printf("`~` Not a Valid Prefix Expression `~`");
    }
}
