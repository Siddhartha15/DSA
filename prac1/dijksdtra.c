#include<stdio.h>
#include<stdlib.h>
#define inf 1e9

int adj[100][100]={0};
int j=1,visited[1000]={0};
int dis[1001];
//memset(tree,-1,sizeof(tree));
int id[1000];
struct heap
{
	int from;
	int to;
	int weight;
};
struct heap tree[200000];

void upheapify(int node)
{
	if(node==1)
		return;
	if(tree[node].weight<tree[node/2].weight)
	{
		struct heap temp=tree[node];
		tree[node]=tree[node/2];
		tree[node/2]=temp;
	}
	upheapify(node/2);
	return;
}

void downheapify(int node)
{
	if(tree[node].weight==-1) return;
	int hl=tree[2*node].weight,hr=tree[2*node+1].weight;
		if(hl==-1) hl=1000000;
		if(hr==-1) hr=1000000;
		if((hl<hr)&&(hl<tree[node].weight))
		{
			struct heap temp=tree[node];
			tree[node]=tree[2*node];
			tree[2*node]=temp;
			downheapify(2*node);
		}
		else if(hr<tree[node].weight)
		{
			struct heap temp=tree[node];
			tree[node]=tree[2*node+1];
			tree[2*node+1]=temp;
			downheapify(2*node+1);			
		}
	return;	
}


/*void display(int node)
{
	if(tree[node]==-1)
		return;
	printf("%d ",tree[node]);
	display(2*node);
	display(2*node+1);
	return ;
}
*/
void dijkstra(int s)
{
	int i;
	tree[1].weight=0;
	tree[1].from=0;
	tree[1].to=s;
	j++;
	dis[s]=0;
	while(j!=1)
	{
		int u=tree[1].from;
		int v=tree[1].to;
		int w=tree[1].weight;
		j--;
		tree[1]=tree[j];
		tree[j].weight=-1;
		downheapify(1);
		if(visited[v]) continue;
		visited[v]=1;
	//	result[u][v]=w;
	//	result[v][u]=w;
		printf("%d %d %d\n",u,v,w);
		for(i=1;i<100;i++)
		{
			if(adj[v][i])
			{
				//int w;
				if(dis[v]+adj[v][i]<dis[i])
				{
					dis[i]=dis[v]+adj[v][i];
					tree[j].from=v;
					tree[j].to=i;
					tree[j].weight=dis[i];
					upheapify(j);
					j++;
				}
			}
		}
	}
	return;
}

int main()
{
	int n,i,m,s;
	printf("Enter the numebr of nodes and edges \n");
	scanf("%d%d",&n,&m);
	printf("Enter the edges \n");
	for(i=0;i<200000;i++) tree[i].weight=-1;
	for(i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		adj[u][v]=w;
		adj[v][u]=w;
	}
	printf("Enter the source vertex \n");
	scanf("%d",&s);
	for(i=1;i<=n;i++) dis[i]=inf;
	dijkstra(s);
	for(i=1;i<=n;i++)
		printf("%d\n",dis[i]);
	return 0;
}