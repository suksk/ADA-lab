#include <stdio.h>
#define infinity 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Creating cost matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (Graph[i][j] == 0)
                cost[i][j] = infinity;
            else
                cost[i][j] = Graph[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = infinity;
        for (i = 0; i < n; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
        // printing the distance
        for (i = 0; i < n; i++)
        {
            if (i != start)
                printf("\nDistance from source to %d: %d", i, distance[i]);
        }
    }
}

int main()
{
    int Graph[MAX][MAX], i, j, n, u;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("ENter the weighted graph:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &Graph[i][j]);
        }
    }
    u = 0;
    Dijkstra(Graph, n, u);
}
