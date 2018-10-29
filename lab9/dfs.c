#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
}*A[1000];

bool visited[100];

struct node *getNode(int x)
{
    struct node *ptr=(struct node*)malloc(sizeof(ptr));
    ptr->data=x;
    ptr->next=NULL;
    return ptr;

}

void insert(int u,int v)
{
    struct node *p,*c;
    c=getNode(v);
    if(A[u]==NULL)
    {
        A[u]=c;
    }
    else
    {
        p=A[u];
        while(p->next!=NULL)
            p=p->next;
        p->next=c;
    }
    return ;
}

void DFS(int x)
{
    visited[x]=true;
    printf("%d\n",x);
    struct node *temp=A[x];
    while(temp!=NULL)
    {
        if(visited[temp->data]==false)
            DFS(temp->data);
         temp=temp->next;
    }
}

int main()
{
    int n,m,u,v,i;
    printf("enter the number of nodes and edges\n");
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        printf("Enter the edge:");
        scanf("%d %d",&u,&v);
        insert(u,v);
        insert(v,u);
    }

    printf("Graph representation :\n");
    for(i=1;i<=n;i++)
    {
        printf("%d : ",i);
        struct node *temp=A[i];
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

    int x;
    printf("enter the node from while you want DFS :");
    scanf("%d",&x);
    printf("DFS of graph :\n");
    DFS(x);
    return 0;
}