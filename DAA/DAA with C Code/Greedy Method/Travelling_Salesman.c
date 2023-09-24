#include <stdio.h>
#include <limits.h>

int cost = 0;

int min(int city, int city_matrix[city][city], int visited[city], int start)
{
    int i;
    int new_city = INT_MAX, min = INT_MAX;
    for (i = 0; i < city; i++)
    {
        if (city_matrix[start][i] != 0 && visited[i] == 0)
        {
            if (min > city_matrix[start][i])
            {
                min = city_matrix[start][i];
                new_city = i;
            }
        }
    }

    if (min != INT_MAX)
    {
        cost += min;
    }
    return new_city;
}

void TSP(int city, int city_matrix[city][city], int visited[city], int start)
{
    int i, new_city;

    visited[start] = 1;

    printf("City%d -> ", start + 1);

    new_city = min(city, city_matrix, visited, start);

    if (new_city == INT_MAX)
    {
        new_city = 0;
        printf("City%d", new_city + 1);
        cost += city_matrix[start][new_city];
        return;
    }

    TSP(city, city_matrix, visited, new_city);
}

int main()
{
    int city, start;
    printf("Enter the total no. of cities = ");
    scanf("%d", &city);

    int city_matrix[city][city], visited[city];

    printf("\n\t** Enter the travel cost of the cities in matrix format **\n");
    for (int i = 0; i < city; i++)
    {
        for (int j = 0; j < city; j++)
        {
            scanf("%d", &city_matrix[i][j]);
        }
        visited[i] = 0;
    }

    printf("\n\t** Travelling Cities With Cost **\n");
    for (int k = 0; k < city; k++)
    {
        printf("\tCity%d", k + 1);
    }
    printf("\n");
    for (int i = 0; i < city; i++)
    {
        printf("City%d\t", i + 1);
        for (int j = 0; j < city; j++)
        {
            printf("%d\t ", city_matrix[i][j]);
        }
        printf("\n");
    }

    printf("Enter the start city = ");
    scanf("%d", &start);

    printf("\nTravelling Paths : ");
    TSP(city, city_matrix, visited, start - 1);
    printf("\nMinimum Travelling Cost = %d", cost);
}