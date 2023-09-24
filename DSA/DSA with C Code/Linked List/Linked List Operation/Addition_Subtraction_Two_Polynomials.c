#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Create Structure
struct pol
{
    char op;
    int coeff;
    int exp;
    struct pol *next;
};

// create polynomial1 , polynomial2 , Addpolynomial
struct pol *poly1 = NULL, *poly2 = NULL, *poly = NULL;
char alpha;

// Function for create polynomial in linked list
struct pol *create_poly(char m, int x, int y, struct pol *head)
{
    struct pol *temp, *current;

    if (head == NULL)
    {
        // create temp node
        temp = (struct pol *)malloc(sizeof(struct pol));

        temp->op = m;  // push operator in linked list
        temp->coeff = x; // push coefficient in linked list
        temp->exp = y; // push exponent in linked list

        temp->next = NULL;
        head = temp;
    }
    else
    {
        // set temp as head
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // create current node
        current = (struct pol *)malloc(sizeof(struct pol));

        current->op = m;    // push operator in linked list
        current->coeff = x; // push coefficient in linked list
        current->exp = y;   // push exponent in linked list

        current->next = NULL;
        temp->next = current;
    }

    // return head linked list 
    return head;
}

// Function for convert a string to polynomial expression
void convert(char P[100], int count)
{
    char operator;

    // condition for default operator
    if (P[0] == '-')
    {
        operator= P[0];
    }
    else
    {
        operator= '+';
    }

    int d, e = 0, i = 0, j = 0, flag;

    while (P[i] != '\0')
    {
        // condition for polynomial character is a number or not
        if (isdigit(P[i]))
        {
            d = P[i] - 48; // convert character to number
            e = e * 10 + d; // e store the 2 digit or more than numbers..like 165
        }

        // condition for polynomial character is a alphabet or not
        else if (isalpha(P[i]))
        {
            alpha = P[i]; // store the alphabet
        }

        // condition for polynomial character is a exponent sign or not
        else if (P[i] == '^')
        {
            flag = e; // set flag as the value of coefficient
            e = 0; // set e = 0
        }

        // condition for polynomial character is + or -
        else if (P[i] == '+' || P[i] == '-')
        {
            // For Polynomial1 count is 0
            if (count == 0 && i != 0)
            {
                // call function for creating a polynimal linked list
                // flag is coefficient value
                // e is exponent value
                // operator is either + or -
                poly1 = create_poly(operator, flag, e, poly1);
            }

            // For Polynomial1 count is 1
            else if (count == 1 && i != 0)
            {
                poly2 = create_poly(operator, flag, e, poly2);
            }

            operator= P[i];
            e = 0;
        }
        i++;
    }
    if (count == 0 && i != 0)
    {
        poly1 = create_poly(operator, flag, e, poly1);
    }
    else if (count == 1 && i != 0)
    {
        poly2 = create_poly(operator, flag, e, poly2);
    }
}

// Function for sort the polynomial linked list as decending order
struct pol *sortList(struct pol *head)
{
    //Node current will point to head
    struct pol *current = head, *index = NULL;
    int co, po;
    char ope;

    if (head == NULL)
    {
        return 0;
    }
    else
    {
        while (current != NULL)
        {
            //Node index will point to node next to current
            index = current->next;

            while (index != NULL)
            {
                //If current node's data is less than index's node data, swap the data between them
                if (current->exp < index->exp)
                {
                    co = current->coeff;
                    po = current->exp;
                    ope = current->op;

                    current->coeff = index->coeff;
                    current->exp = index->exp;
                    current->op = index->op;

                    index->coeff = co;
                    index->exp = po;
                    index->op = ope;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
    return head;
}

// Function for Performing Operation between two Polynomial
struct pol *polyadd(struct pol *poly1, struct pol *poly2, struct pol *poly)
{
    struct pol *p1 = poly1, *p2 = poly2, *add;

    while (p1 != NULL && p2 != NULL)
    {
        if (poly == NULL)
        {
            poly = (struct pol *)malloc(sizeof(struct pol));
            add = poly;
        }
        else
        {
            add->next = (struct pol *)malloc(sizeof(struct pol));
            add = add->next;
        }

        // Condition for p1 exponent is greater than p2 exponent then push into new linked list 
        if (p1->exp > p2->exp)
        {
            add->op = p1->op;
            add->coeff = p1->coeff;
            add->exp = p1->exp;
            p1 = p1->next;
        }

        // Condition for p1 exponent is less than p2 exponent then push into new linked list
        else if (p1->exp < p2->exp)
        {
            add->op = p2->op;
            add->coeff = p2->coeff;
            add->exp = p2->exp;
            p2 = p2->next;
        }

        // Condition for p1 exponent and p2 exponent both are equal then performing below operation
        else if (p1->exp == p2->exp)
        {
            // Check if both operator is same then performing addtion and push the operator and answer in linked list
            if (p1->op == p2->op)
            {
                add->op = p1->op;
                add->coeff = p1->coeff + p2->coeff;
                add->exp = p1->exp;
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->op == '+' && p2->op == '-')
            {
                if (p1->coeff > p2->coeff)
                {
                    add->op = '+';
                    add->coeff = p1->coeff - p2->coeff;
                    add->exp = p1->exp;
                    p1 = p1->next;
                    p2 = p2->next;
                }
                else
                {
                    add->op = '-';
                    add->coeff = p2->coeff - p1->coeff;
                    add->exp = p1->exp;
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }
            else if (p1->op == '-' && p2->op == '+')
            {
                if (p1->coeff > p2->coeff)
                {
                    add->op = '-';
                    add->coeff = p1->coeff - p2->coeff;
                    add->exp = p1->exp;
                    p1 = p1->next;
                    p2 = p2->next;
                }
                else
                {
                    add->op = '+';
                    add->coeff = p2->coeff - p1->coeff;
                    add->exp = p1->exp;
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }
        }
    }
    while (p1 != NULL)
    {
        add->next = (struct pol *)malloc(sizeof(struct pol));
        add = add->next;
        add->op = p1->op;
        add->coeff = p1->coeff;
        add->exp = p1->exp;
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        add->next = (struct pol *)malloc(sizeof(struct pol));
        add = add->next;
        add->op = p2->op;
        add->coeff = p2->coeff;
        add->exp = p2->exp;
        p2 = p2->next;
    }

    add->next = NULL;
    return poly;
}

void display(struct pol *temp)
{
    struct pol *ptr = temp;
    while (ptr != NULL)
    {
        if (ptr->exp == 0)
        {
            printf("%c %d ", ptr->op, ptr->coeff);
            ptr = ptr->next;
        }
        else if (ptr->exp == 1 && ptr->coeff!=0)
        {
            printf("%c %d%c ", ptr->op, ptr->coeff, alpha);
            ptr = ptr->next;
        }
        else if(ptr->coeff!=0)
        {
            printf("%c %d%c^%d ", ptr->op, ptr->coeff, alpha, ptr->exp);
            ptr = ptr->next;
        }
        else{
            printf("%c %d ", ptr->op, ptr->coeff);
            ptr = ptr->next;
        }
    }
}

int main()
{
    char First_Pol[100], Second_Pol[100], count = 0;

    printf("\nEnter 1st Polynomial = ");
    gets(First_Pol);

    printf("Enter 2nd Polynomial = ");
    gets(Second_Pol);

    convert(First_Pol, count);
    count++;
    convert(Second_Pol, count);

    poly1 = sortList(poly1);
    poly2 = sortList(poly2);

    poly = polyadd(poly1, poly2, poly);

    printf("\nFirst Polynomial is =\t\t");
    display(poly1);
    printf("\nSecond Polynomial is =\t\t");
    display(poly2);
    printf("\n\t\t\t----------------------------------------");
    printf("\nResult of two Polynomial =\t");
    display(poly);
}