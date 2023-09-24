// Graph Representation Using Adjacency Matrix

#include <stdio.h>

void PrintGraph(int v, int Graph[v][v])
{
    int i, j;
    printf("\n****  Graph   ****\n");

    for (i = 0; i < v; i++)
    {
        printf("%d -- ", i);
        for (j = 0; j < v; j++)
        {
            if (Graph[i][j] == 1)
            {
                printf("%d -- ",j);
            }
        }
        printf("X\n");
    }
}

int main()
{
    int v;
    printf("Enter the total no. of vertices = ");
    scanf("%d", &v);

    printf("\nEnter the edges of Adjacency Matrix : \n");
    int Graph[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &Graph[i][j]);
        }
    }

    PrintGraph(v, Graph);
}