//  Breadth First Search

#include <stdio.h>
#include <stdlib.h>

struct BFS_Queue
{
    int Size;
    int front;
    int rear;
    int *queue;
};

int isEmpty(struct BFS_Queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct BFS_Queue *q)
{
    if (q->rear == q->Size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int enqueue(struct BFS_Queue *q, int val)
{
    if (isFull(q))
    {
        printf("\n** Queue is Full **");
    }
    else
    {
        q->rear++;
        q->queue[q->rear] = val;
    }
}

int dequeue(struct BFS_Queue *q)
{
    int val;
    if (isEmpty(q))
    {
        printf("\n** Queue is Empty **");
    }
    else
    {
        q->front++;
        val = q->queue[q->front];
    }
    return val;
}

int BFS_Traversal(struct BFS_Queue *q, int vertex, int arr[vertex][vertex], int visited[vertex], int Root)
{
    printf("%d ", Root);
    visited[Root] = 1;
    enqueue(q, Root);

    while (!isEmpty(q))
    {
        int node = dequeue(q);
        for (int edge = 0; edge < vertex; edge++)
        {
            if (arr[node][edge] == 1 && visited[edge] == 0)
            {
                printf("%d ", edge);
                visited[edge] = 1;
                enqueue(q, edge);
            }
        }
    }
}

int main()
{
    struct BFS_Queue q;
    int vertex;

    printf("Enter the total no.of Vertices = ");
    scanf("%d", &vertex);

    q.Size = 1000;
    q.front = q.rear = 0;
    q.queue = (int *)malloc(q.Size * (sizeof(int)));

    int Root, arr[vertex][vertex], visited[vertex];

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

    printf("Breadth First Search = ");
    BFS_Traversal(&q, vertex, arr, visited, Root);

    return 0;
}
