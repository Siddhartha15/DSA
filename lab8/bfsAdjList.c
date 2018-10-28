#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
}*A[1000];

bool visited[100];
int queue[1000],front=-1,rear=-1;

void enqueue(int x)
{
    if(front==-1&&rear==-1)
    {
        front=0;rear=0;
        queue[rear]=x;
        return ;
    }

    if(rear==999)
    {
        printf("Queue is full\n");
        return ;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
    //printf("$$$$ %d %d %d\n",rear,x,queue[rear]);
    //printf("Enqueued\n");
}

bool Isempty()
{
    if((front==-1 && rear==-1) || front>rear)
    {
        return true;
    }
    return false;
}

void dequeue()
{
    //printf("Dqueue\n");
    if(Isempty())
    {
        printf("queue is empty\n");
        return ;
    }
    if(front==rear&&rear!=0)
    {
        front=-1;rear=-1;
        return ;
    }
    front++;
    return ;
}

int front_()
{
    if(Isempty())
    {
        printf("Queue is empty\n");
        return ;
    }

    //printf("### %d",queue[front]);
    return queue[front];
}

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

void BFS(int x)
{
     visited[x]=true;
     printf("%d ",x);
     enqueue(x);
     while(!Isempty())
     {
         int num=front_();
         dequeue();
         struct node *temp=A[num];
        // printf("Here %d\n",num);
         while(temp!=NULL)
         {
             if(visited[temp->data]==false)
             {
                 enqueue(temp->data);
                 printf("%d ",temp->data);
                 visited[temp->data]=true;
             }
             temp=temp->next;
         }
     }
}

int main()
{
    int N,M,i,u,v;
    printf("Enter the number of nodes and edges :");
    scanf("%d %d",&N,&M);

    for(i=0;i<M;i++)
    {
        printf("Enter the edge :");
        scanf("%d %d",&u,&v);
        insert(u,v);
        insert(v,u);
    }

    printf("Graph representation :\n");
    for(i=1;i<=N;i++)
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
    printf("Enter the node from which you want BFS :");
    scanf("%d",&x);

    printf("BFS traversal : ");

    BFS(x);

    return 0;
}