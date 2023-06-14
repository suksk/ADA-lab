#include<stdio.h>
#include<stdlib.h>

int a[30][30], visited[30], dfsarray[30], n, acyclic=1, thiscount=-1, i, j;

void dfs(int v)
{
     dfsarray[++thiscount] = v;
     visited[v] = 1;
     for(i=1; i<=n; i++)
     {
         if(a[v][i] && visited[i])
        {
            acyclic=0;
            printf("%d->%d\n", v, i);
        }
        if(a[v][i] && !visited[i])
        {
           
            printf("%d->%d\n", v, i);
            dfs(i);
        }
     }
}

void connectedandcyclic()
{
    int count = 0;
    for(i=1; i<=n; i++)
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
    dfs(start);
    dfsarray[++thiscount] = start;
    connectedandcyclic();
    printf("\nThe bfs traversal is:\n");
    for(i=0; i<n; i++)
    printf("%d->",dfsarray[i]);
}