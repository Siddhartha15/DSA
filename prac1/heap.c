#include<stdio.h>
#include<stdlib.h>

int tree[200000],j=1;
//memset(tree,-1,sizeof(tree));

void upheapify(int node)
{
	if(node==1)
		return;
	if(tree[node]<tree[node/2])
	{
		int temp=tree[node];
		tree[node]=tree[node/2];
		tree[node/2]=temp;
	}
	upheapify(node/2);
	return;
}

void downheapify(int node)
{
	if(tree[node]==-1) return;
	int hl=tree[2*node],hr=tree[2*node+1];
		if(hl==-1) hl=1000000;
		if(hr==-1) hr=1000000;
		if((hl<hr)&&(hl<tree[node]))
		{
			int temp=tree[node];
			tree[node]=hl;
			tree[2*node]=temp;
			downheapify(2*node);
		}
		else if(hr<tree[node])
		{
			int temp=tree[node];
			tree[node]=hr;
			tree[2*node+1]=temp;
			downheapify(2*node+1);			
		}
	return;	
}

void display(int node)
{
	if(tree[node]==-1)
		return;
	printf("%d ",tree[node]);
	display(2*node);
	display(2*node+1);
	return ;
}

int main()
{
	int n,i;
	for(i=0;i<200000;i++) tree[i]=-1;
	printf("Enter 1)Insert 2)Delete root 3)Display preorder 4)Exit\n");
	scanf("%d",&n);
	while(n!=4)
	{
		if(n==1)
		{
			scanf("%d",&i);
			tree[j]=i;
			upheapify(j);
			j++;
		}
		else if(n==2)
		{
			printf("%d\n",tree[1]);
			tree[1]=tree[j-1];
			//printf("%d\n",tree[1]);			
			tree[j-1]=-1;
			j--;
			downheapify(1);
		}
		else
		{
			display(1);
			printf("\n");
		}
		printf("Enter 1)Insert 2)Delete root 3)Display preorder 4)Exit\n");
		scanf("%d",&n);
	}
	return 0;
}