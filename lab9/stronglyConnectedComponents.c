#include<stdio.h>
#include<stdlib.h>

int n,transpose=0;//number of vertices

void swap(int *x, int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

int stack[30];
int top=-1;

int isEmpty()
{	return top==-1;	}

void push(int key)
{
	if(top>n)
	{
		printf("\nStack overflow\n");
		return;
	}
	stack[++top]=key;
}

int pop()
{	return stack[top--];	}

typedef struct graph
{
	int g[30][30];
	int *visited;
}graph;

graph* createGraph()
{
	graph *G=(graph *)malloc(sizeof(graph));
	G->visited=(int *)calloc(n,sizeof(int));
	return G;
}

void getGraph(graph *G)
{
	int i,j;
	for(int i=0;i<n;i++)
		G->g[i][i]=0;
	printf("\nEnter the vertices which have edges between them (-1 to exit)\n");
	while(1)
	{
		scanf("%d%d",&i,&j);
		if(i==-1 && j==-1)
			break;
		G->g[i-1][j-1]=1;
	}
}

void DFS(graph *G,int i)
{
	G->visited[i]=1;
	for(int j=0;j<n;j++)
		if(!G->visited[j] && G->g[i][j])
			DFS(G,j);
	if(!transpose)
		push(i);
	else
		printf("%d ",i+1);
}

void DFS_traversal(graph* G)
{
	for(int i=0;i<n;i++)
		if(!G->visited[i])
			DFS(G,i);
}

void main()
{
	int s;
	printf("\nEnter the number of vertices ");
	scanf("%d",&n);
	graph *G=createGraph();
	getGraph(G);
	printf("\nOriginal graph\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",G->g[i][j]);
		printf("\n");
	}
	printf("\nEnter the starting vertex ");
	scanf("%d",&s);
	DFS_traversal(G);
	printf("\n");
	printf("\nTranspose graph\n");

	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			swap(&G->g[i][j],&G->g[j][i]);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",G->g[i][j]);
		printf("\n");
	}

	transpose=1;
	printf("\n");
	for(int i=0;i<n;i++)
		G->visited[i]=0;
	while(!isEmpty())
	{
		int temp = pop();
		if(!G->visited[temp])
		{
			DFS(G,temp);
			printf("\n");
		}
	}
	printf("\n");
}