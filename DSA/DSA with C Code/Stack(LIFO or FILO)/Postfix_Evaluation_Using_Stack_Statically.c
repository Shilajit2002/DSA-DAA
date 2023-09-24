#include <stdio.h>
#include <ctype.h>
#include <math.h>

// Set the Value of variables
int top = -1;
double stack[100];
int i = 0, space = 0;
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
            double num1;
            num1 = Pop();                  // pop the previous number
            stack[++top] = el + 10 * num1; // now popping number multiply by 10 and adding the new number then push into the stack
        }
        // if space between two numbers then
        else if (space == 0)
        {
            stack[++top] = el; //push the number into stack
            space = 1;
        }
    }
}

// Postfix evaluation function
int PostfixEvaluation(char P[100])
{
    double n1, n2, n3, num;
    int n4, n5, n6;
    // Until the becomes end
    while (P[i] != '\0')
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
                n3 = n2 + n1; // then add two number
                break;
            }
            // elemnt is - operator
            case '-':
            {
                n3 = n2 - n1; // then substract two number
                break;
            }
            // elemnt is * operator
            case '*':
            {
                n3 = n2 * n1; // then multiply two number
                break;
            }
            // elemnt is / operator
            case '/':
            {
                n3 = n2 / n1; // then divide two number
                break;
            }
            // elemnt is % operator
            case '%':
            {
                n6 = n2, n5 = n1;
                n4 = n6 % n5; // then modulus two number
                break;
            }
            // elemnt is ^ operator
            case '^':
            {
                n3 = pow(n2, n1); // then n2 to the power n1
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
        i++;
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
    printf("Enter the Postfix Expression : ");
    gets(P);
    if (PostfixEvaluation(P))
    {
        printf("Postfix Evaluation is : %.0lf", end);
    }
    else
    {
        printf("`~` Not a Valid Postfix Expression `~`");
    }
}
