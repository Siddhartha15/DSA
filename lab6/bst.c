#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* left;
  struct node* right;
};
struct node* root=NULL;
struct node* buildnode(int key)
{
  struct node* ptr=(struct node *)malloc(sizeof(struct node));
  ptr->data=key;
  ptr->left=NULL;
  ptr->right=NULL;
  return ptr;
}
struct node* insert(struct node *root,int key)
{
  if(root==NULL)
    return buildnode(key);
  if(key < root->data)
    root->left=insert(root->left,key);
  else if(key > root->data)
    root->right=insert(root->right,key);
  return root;
}
void inorder(struct node* root)
{
  if(root == NULL)
    return;
  inorder(root->left);
  printf(" %d ",root->data);
  inorder(root->right);
}
struct node* findmin(struct node* root)
{
  struct node*c=root;
  while(c->left != NULL)
    c=c->left;
  return c;
}
struct node* delete(struct node* root,int key)
{
  if(root==NULL)
    return root;
  if(key < root->data)
    root->left=delete(root->left,key);
  else if(key > root->data)
    root->right=delete(root->right,key);
  else
  {
    //case1
    if(root->left==NULL && root->right==NULL)
    {
      root=NULL;
    }
    else if(root->left==NULL)
    {
      struct node* temp=root;
      root=root->right;
      free(temp);
    }
    else if(root->right==NULL)
    {
      struct node* temp=root;
      root=root->left;
      free(temp);
    }
    else
    {
        struct node* temp=findmin(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;
  }
}
void main()
{
  int val,c,k;
  printf("create BST\nEnter root value\n");
  scanf("%d",&val);
  root=insert(root,val);
  while(1)
  {
    printf("enter val or -999 to stop\n");
    scanf("%d",&val);
    if(val==-999)
      break;
    insert(root,val);
  }
  while(1)
  {
    printf("enter 1-delete,2-inorder,3-exit\n");
    scanf("%d",&c);
    if(c==1)
    {
      printf("enter key \n");
      scanf("%d",&k);
      //printf("\n%d\n",k);
      delete(root,k);
    }
    else if(c==2)
    {
      inorder(root);
      printf("\n");
    }
    else
      break;
  }
}