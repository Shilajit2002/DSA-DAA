#include <stdio.h>

int G[1000][1000], m, color_tab[100], v1, v2, i, j, n, a, b;

void Gen_Col_Value(int k, int n)
{
    while (1)
    {
        a = color_tab[k] + 1;
        b = m + 1;
        color_tab[k] = a % b;
        if (color_tab[k] == 0)
            return;
        for (j = 1; j <= n; j++)
        {
            if (G[k][j] && color_tab[k] == color_tab[j])
                break;
        }
        if (j == n + 1)
            return;
    }
}

void Gr_coloring(int k, int n)
{
    Gen_Col_Value(k, n);
    if (color_tab[k] == 0)
        return;
    if (k == n)
        return;
    else
        Gr_coloring(k + 1, n);
}

int main()
{
    printf("\nEnter the total no. of Vertex = ");
    scanf("%d", &n);
    m = n - 1;
    printf("\nEnter the Adjacency Matrix of the Graph : \n");
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }
    Gr_coloring(1, n);
    printf("\n The Vertices To be Coloured As...\n");
    for (i = 1; i <= n; i++)
    {
        switch (color_tab[i])
        {
        case 1:
            printf("\n V%d => RED", i);
            break;
        case 2:
            printf("\n V%d => BLUE", i);
            break;
        case 3:
            printf("\n V%d => YELLOW", i);
            break;
        case 4:
            printf("\n V%d => GREEN", i);
            break;
        case 5:
            printf("\n V%d => ORANGE", i);
            break;
        default:
            printf("\n V%d => WHITE", i);
            break;
        }
    }
    return 0;
}
