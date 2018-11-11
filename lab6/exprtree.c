#include<stdio.h>
//#include<conio.h>
//#include<alloc.h>
#include<stdlib.h>
#include<string.h>

struct tree
{
    char data;
    struct tree *left,*right;
};

int top=-1;
struct tree *stack[20];
struct tree *node;

void push(struct tree* node)
{
    stack[++top]=node;
}

struct tree * pop()
{
    return(stack[top--]);
}
int check(char ch)
{
  if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
    return 2;
  else
    return 1;
}
void inorder(struct tree *node)
{
    if(node!=NULL)
    {
      inorder(node->left);
      printf("%c",node->data);
      inorder(node->right);
    }
}

void operand(char b)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=b;
    node->left=NULL;
    node->right=NULL;
    push(node);
}
void operators(char a)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=a;
    node->right=pop();
    node->left=pop();
    push(node);
}

void main()
{
    int i,p,k,ans;
    char s[20];
    printf("Enter the expression in postfix form \n");
    scanf("%s",s);
    k=strlen(s);
    i=0;
    for(i=0;s[i]!='\0';i++)
        {
            p=check(s[i]);
            if(p==1)
            operand(s[i]);
            else if(p==2)
            operators(s[i]);
        }
    printf("The inorder is \n");
    inorder(stack[top]);
    printf("\n");
}