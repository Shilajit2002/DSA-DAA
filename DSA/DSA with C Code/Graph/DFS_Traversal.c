//  Depth First Search

#include <stdio.h>

int vertex, arr[1000][1000], visited[1000];

int DFS_Traversal(int Root)
{
    printf("%d ", Root);
    visited[Root] = 1;

    for (int edge = 0; edge < vertex; edge++)
    {
        if (arr[Root][edge] == 1 && !visited[edge])
        {
            DFS_Traversal(edge);
        }
    }
}

int main()
{
    printf("Enter the total no.of Vertices = ");
    scanf("%d", &vertex);

    int Root;

    for (int i = 0; i < vertex; i++)
    {
        visited[i] = 0;
    }

    printf("\nEnter the Adjecency Matrix of the Graph\n");
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n Enter the Root Vertex of the Graph = ");
    scanf("%d", &Root);

    printf("Depth First Search = ");
    DFS_Traversal(Root);

    return 0;
}
