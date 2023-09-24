// Graph Representation Using Adjacency List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int NumVertices;
    struct Node **adjLists;
};

struct Node *CreateNode(int V)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->vertex = V;
    newnode->next = NULL;

    return newnode;
}

struct Graph *CreateGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->NumVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node *));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void AddEdge1(struct Graph *graph, int s, int d)
{
    struct Node *newnode = CreateNode(d);
    newnode->next = graph->adjLists[s];
    graph->adjLists[s] = newnode;
}

void AddEdge2(struct Graph *graph, int s, int d)
{
    struct Node *newnode = CreateNode(d);
    newnode->next = graph->adjLists[s];
    graph->adjLists[s] = newnode;

    newnode = CreateNode(s);
    newnode->next = graph->adjLists[d];
    graph->adjLists[d] = newnode;
}

void PrintGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->NumVertices; v++)
    {
        struct Node *temp = graph->adjLists[v];
        printf("\nVertex %d : ", v);
        while (temp)
        {
            printf("%d - > ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int v;
    printf("Enter the no. of Vertices = ");
    scanf("%d", &v);

    struct Graph *graph = CreateGraph(v);

    int G;
    printf("\n1.Directed Graph\n2.Undirected Graph\nEnter your choice : ");
    scanf("%d", &G);

    int s, d, ch;
    do
    {
        printf("Enter Source = ");
        scanf("%d", &s);
        printf("Enter Destination = ");
        scanf("%d", &d);

        if (G == 1)
        {
            AddEdge1(graph, s, d);
        }
        else if (G == 2)
        {
            AddEdge2(graph, s, d);
        }

        printf("\nFor Enter another vertex press 1 otherwise press 0 for stop = ");
        scanf("%d", &ch);

    } while (ch);

    printf("\n****  Graph   ****\n");
    PrintGraph(graph);
}
