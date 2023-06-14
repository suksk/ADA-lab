#include<stdio.h>
#include<stdlib.h>

int a[30][30], visited[30], q[30], i, j, n,f=0,r=-1, acyclic = 1, bfsarray[30], thiscount=-1; 

void bfs(int v)
{
    bfsarray[++thiscount] = v;
    for(i = 1; i<=n ; i++)
    {
        if(a[v][i] && visited[i])
        {
            acyclic=0;
            printf("%d->%d\n", v, i);
        }
        if(a[v][i] && !visited[i])
        {
            q[++r] = i; //insert the vertex into the queue
            printf("%d->%d\n", v, i);
        }
    }
    if(r>=f)
    {
        
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}

void connectedandcyclic()
{
    int count = 1;
    //count the no. of vertices in bfs traversal
    for(int i=1;i<n;i++)
    {
        if(visited[i])
        count++;
    }
    if(count == n)
    {
        printf("\nGraph is connected");
    }
    else
    {
        printf("\nGraph is not connected");
    }
    if(acyclic)
    {
        printf("\nGraph is acyclic");
    }
    else
    {
        printf("\nGraph is cyclic");
    }
}

int main()
{
    int start;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    //Initialize the visited array with zeros
    for(i=1; i<=n; i++)
    visited[i] = 0;

    printf("Enter the adjacency matrix:\n");
    
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the starting vertex:");
    scanf("%d",&start);
    visited[start] = 1;
    bfs(start);
    bfsarray[++thiscount] = start;
    connectedandcyclic();
    printf("\nThe bfs traversal is:\n");
    for(i=0; i<n; i++)
    printf("%d->",bfsarray[i]);
}