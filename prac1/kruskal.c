#include<stdio.h>
#include<stdlib.h>

int adj[100][100]={0};
int j=1,visited[1000]={0};
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
int root(int x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void unite(int p,int q)
{
	int root_p=root(p),root_q=root(q);
	id[root_p]=root_q;
	return;
}

void kruskal()
{
	int i;
	for(i=1;tree[1].weight!=-1;)
	{
		int u=tree[1].from;
		int v=tree[1].to;
		int w=tree[1].weight;
		j--;
		tree[1]=tree[j];
		tree[j].weight=-1;
		downheapify(1);
		//printf("%d\n",w);
		if(root(u)!=root(v))
		{
			unite(u,v);
			adj[u][v]=w;
			adj[v][u]=w;
		}
	}
	return;
}

int main()
{
	int n,i,m;
	printf("Enter the numebr of nodes and edges \n");
	scanf("%d%d",&n,&m);
	printf("Enter the edges \n");
	for(i=0;i<200000;i++) tree[i].weight=-1;
	for(i=0;i<1000;i++) id[i]=i;
	for(i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		tree[j].from=u;
		tree[j].to=v;
		tree[j].weight=w;
		upheapify(j);
		j++;
	}
	kruskal();
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			if(adj[i][j])
				printf("%d %d %d\n",i,j,adj[i][j]);
		}
	}
	return 0;
}