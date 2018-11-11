#include<stdio.h>
#include<stdlib.h>
#define size 100
struct node{
    int data;
    struct node* next;
}*A[size];
int stack[size];
int top=-1;
int visited[size];
struct node* getnode(int v2)
{
    struct node* t=(struct node *)malloc(sizeof(struct node));
    t->data=v2;
    t->next=NULL;
    return t;
}
void insert(int v1,int v2)
{
    struct node *p,*c;
    c=getnode(v2);
    if(A[v1] == NULL)
        A[v1]=c;
    else{
        p=A[v1];
        while(p->next !=NULL)
        {
            p=p->next;
        }
        p->next=c;
    }
}
void push(int x)
{
    top++;
    stack[top]=x;
}
void pop()
{
    if(top == -1)
    {
        printf("stack is empty\n");
        return;
    }
    top--;
}
void DFS(int key)
{
    visited[key]=1;
    push(key);
    while(top != -1)
    {
        int v=stack[top];
        printf("%d ",v);
        pop();
        struct node* t=A[v];
        while(t!=NULL)
        {
            if(visited[t->data] == 0 )
            {
                push(t->data);
                visited[t->data]=1;
            }
            t=t->next;   
        }
    }
}
void main()
{
    printf("create a graph\n");
    int v,e,i,v1,v2;
    printf("enter the no of nodes and vertices(v e)\n");
    scanf("%d %d",&v,&e);
    for(i=0;i<e;i++)
    {
        printf("enter the edges(v1 v2)\n");
        scanf("%d %d",&v1,&v2);
        insert(v1,v2);
        insert(v2,v1);
    }
    printf("enter the source key\n");
    int key;
    scanf("%d",&key);
    printf("the dfs traversal:");
    DFS(key);
}