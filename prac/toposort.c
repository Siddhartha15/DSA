#include <stdio.h>
#include <stdlib.h>
#define size 100

int adjmat[size][size], v;
int visited[size];
int indeg[size];
int queue[size] = {-1}, f = -1, r = -1;
int isempty()
{
    if ((f == -1 && r == -1) || (f > r))
        return 1;
    else
        return 0;
}
void enqueue(int val)
{
    if (f == -1 && r == -1)
    {
        f = 0;
        r = 0;
        queue[r] = val;
        return;
    }
    r++;
    queue[r] = val;
}
void dequeue()
{
    if (isempty())
    {
        printf("queue is empty\n");
        return;
    }
    if (f == r && r != 0)
    {
        f = -1;
        r = -1;
        return;
    }
    f++;
    return;
}
void toposort(int key)
{
    int i, j;
    /*for(i=0;i<v;i++)//including zero as one of the vertex
    {
        for(j=0;j<v;j++)
        {
            if(adjmat[i][j] == 1)
                indeg[j]+=1;
        }
    }

    for(j=0;j<v;j++)
    {
        if(indeg[j] == 0)
         {
            enqueue(j);
            visited[j]=1;
         }  
    }
    
    while(!isempty())
    {
        int x=queue[f];
        dequeue();
        printf("%d ",x);
        for(i=0;i<v;i++)
        {
            if(adjmat[x][j] == 1 && visited[j] == 0)
            {
                indeg[j]--;
            }
            if(indeg[j] == 0)
                {
                    enqueue(j);
                    visited[j]=1;
                }
        }
    }*/
    visited[key] = 1;
    for (i = 0; i < v; i++)
    {
        if (adjmat[key][i] == 1 && visited[i] == 0)
            toposort(i);
    }
    printf("%d ", key);
}

void main()
{
    printf("enter the no of vertices and no of edges\n"); //including zero as one of the vertex
    int i, j, e, v1, v2;
    scanf("%d %d", &v, &e);
    for (i = 0; i < e; i++)
    {
        printf("enter the edges (v1 v2)\n");
        scanf("%d %d", &v1, &v2);
        adjmat[v1][v2] = 1;
    }
    // printf("enter the starting vertex\n");
    //int key;
    //scanf("%d",&key);
    printf("the matrix:\n");
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            printf("%d", adjmat[i][j]);
        printf("\n");
    }
    for(i=0;i<size;i++)
        printf("%d ",queue[i]);
    printf("\nenter the starting vertex\n");
    int key;
    scanf("%d", &key);
    printf("the toposort is(reversed order):");
    toposort(key);
}