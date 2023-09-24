#include <stdio.h>
#include <limits.h>

long S[10000][10000];
long arr[10000];

long mcm(long n, long arr[n])
{
    long matrix[n][n], i, j, k, l, q;

    for (i = 1; i < n; i++)
    {
        matrix[i][i] = 0;
        S[i][i] = 0;
    }

    for (l = 2; l < n; l++)
    {
        for (i = 1; i < n - l + 1; i++)
        {
            j = i + l - 1;
            matrix[i][j] = LONG_MAX;

            for (k = i; k <= j - 1; k++)
            {
                q = matrix[i][k] + matrix[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

                if (q < matrix[i][j])
                {
                    matrix[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }

    return matrix[1][n - 1];
}

long paren(long S[10000][10000], long i, long j)
{
    if (i == j)
    {
        printf("( %ld X %ld )", arr[i - 1], arr[i]);
    }
    else
    {
        printf("( ");
        paren(S, i, S[i][j]);
        paren(S, S[i][j] + 1, j);
        printf(" ) ");
    }
}

int main()
{
    long n;
    printf("Enter the total no. of Degrees = ");
    scanf("%ld", &n);

    printf("Enter the Degrees = ");
    for (long i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }

    printf("\nMinimum number of Multiplication is = %ld\n", mcm(n, arr));

    printf("\nOptimal Parenthesisation is = ");
    paren(S, 1, n - 1);
}