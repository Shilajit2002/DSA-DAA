#include <stdio.h>

void print_matrix(long n, long d[n][n], long pi[n][n])
{
    long i, j;
    printf("\n** All Pair Shortest Path is **\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (d[i][j] == 9999)
            {
                printf("INF\t");
            }
            else
            {
                printf("%ld\t", d[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n** Predecessor Matrix is **\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (pi[i][j] == 0)
            {
                printf("NIL\t");
            }
            else
            {
                printf("%ld\t", pi[i][j]);
            }
        }
        printf("\n");
    }
}

int min(long a, long b)
{
    if (b < a)
    {
        return b;
    }
    else
    {
        return a;
    }
}

void floyd_warshall(long n, long graph[n][n], long Pre[n][n])
{
    long d[n][n], pi[n][n], i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            d[i][j] = graph[i][j];
            pi[i][j] = Pre[i][j];
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (d[i][j] <= d[i][k] + d[k][j])
                {
                    pi[i][j] = pi[i][j];
                }
                else if (d[i][j] > d[i][k] + d[k][j])
                {
                    pi[i][j] = pi[k][j];
                }
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    print_matrix(n, d, pi);
}

int main()
{
    long n;
    printf("Enter the total no of Vertices = ");
    scanf("%ld", &n);

    long graph[n][n], Pre[n][n];

    printf("\n** If Edge have infinity write 9999 **\n");
    printf("\nEnter Edges : \n");
    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j < n; j++)
        {
            scanf("%ld", &graph[i][j]);
        }
    }

    printf("\n** If Predecessor have NIL write 0 **\n");
    printf("\nEnter Predecessor Matrix : \n");
    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j < n; j++)
        {
            scanf("%ld", &Pre[i][j]);
        }
    }
    floyd_warshall(n, graph, Pre);
}