#include <stdio.h>
#include <stdlib.h>
int A[10][10],T[10][10],v[10],v1[10];
struct Stack
{
int top;
unsigned capacity;
int* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int*)malloc(stack->capacity*sizeof(int));
    return stack;
}

int isfull(struct Stack* stack)
{
    return stack->top==stack->capacity-1;
}

int isempty(struct Stack* stack)
{
    return stack->top==-1;
}

void push(struct Stack* stack,int item)
{
    if(isfull(stack))
        return;
    stack->array[++stack->top]=item;
}

int pop(struct Stack* stack)
{
    if(isempty(stack))
        return -1;
    return stack->array[stack->top--];
}

void dfs(int i,int n,struct Stack* stack)
{
    int j;
    //printf("%d ",i);
    push(stack,i);
    v[i]=1;
    for(j=0;j<n;j++)
    if(!v[j]&&A[i][j]==1)
        dfs(j,n,stack);
}

void dfs1(int i,int n,struct Stack* stack)
{
    int j;
    printf("%d ",i);
    //push(stack,i);
    v1[i]=1;
    for(j=0;j<n;j++)
    if(!v1[j]&&T[i][j]==1)
        dfs1(j,n,stack);
                 
}


int main()
{
    struct Stack* stack=createStack(10);
     int n;
    printf("Enter no of vertices : ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            {
                scanf("%d",&A[i][j]);
                T[j][i]=A[i][j];
            }
    dfs(0,n,stack);

    while(stack->top!=-1)
    {
        int x=pop(stack);
        if(!v1[x])
            {
                dfs1(x,n,stack);
                printf("\n");

            }

    }

    return 0;
}