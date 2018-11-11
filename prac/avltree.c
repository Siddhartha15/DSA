#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
    int h;
};
int max(int a,int b)
{
    return a>b?a:b;
}
int getheight(struct tree* root)
{
    if(root=NULL)
        return 0;
    else return root->h;
}
struct tree *buildnode(int key)
{
	struct tree* p=(struct tree*)malloc(sizeof(struct tree));
	p->data=key;
	p->left=NULL;
	p->right=NULL;
	p->h=1;
	return p;
}
struct tree* findmin(struct tree* r)
{
    struct tree* t=r;
    while(!t->left)
    {
        t=t->left;
    }
    return t;
}
struct tree* leftrotate(struct tree *p)
{
    struct tree* A=p->right;
    p->right=A->left;
    A->left=p;
    p->h=1+max(getheight(p->left),getheight(p->right));
    A->h=1+max(getheight(A->left),getheight(A->right));
    
    return A;
}
struct tree* leftrotate(struct tree *p)
{
    struct tree* A=p->left;
    p->left=A->right;
    A->right=p;
    p->h=1+max(getheight(p->left),getheight(p->right));
    A->h=1+max(getheight(A->left),getheight(A->right));
    
    return A;
}
int getbf(struct tree* root)
{
    if(root == NULL)
        return 0;
    else return getheight(root->left)-getheight(root->right);
} 
struct tree* insert(struct tree* root,int data)
{
    if(root == NULL)
        return buildnode(data);
    else if(data < root->data)
        root->left=insert(root->left,data);
    else if(data > root->data)
       root->right=insert(root->right,data);

    root->h=1+max(getheight(root->left),getheight(root->right));

    int bf=getbf(root);

    if(bf>1 && data < root->left->data)
    {
        return rightrotate(root);
    }
    else if(bf<-1 && data > root->right->data)
        return leftrotate(root);
    else if(bf>1 && data > root->left->data)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    else if( bf<-1 && data< root->right->data)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    else 
        return root;
}


struct tree* delete(struct tree* root,int data)
{
    if(root == NULL)
        return NULL;
    else if(data < root->data)
        root->left=delete(root->left,data);
    else if(data > root->data)
       root->right=delete(root->right,data);
    else
    {
        //case1
        if(root->left == NULL && root->right == NULL)
            root=NULL;
        else if(root->left == NULL) //case2
        {
            struct tree* t=root;
            root=root->right;
            free(t);
        }
        else if(root->right == NULL)//case 3
        {
            struct tree* t=root;
            root=root->left;
            free(t);
        }
        else //case 4
        {
            struct tree* t=findmin(t->right);
            root->data=t->data;
            root->right=delete(root->right,t->data);
        }
    }

    root->h=1+max(getheight(root->left),getheight(root->right));

    int bf=getbf(root);

    if(bf>1 && data < root->left->data)
    {
        return rightrotate(root);
    }
    else if(bf<-1 && data > root->right->data)
        return leftrotate(root);
    else if(bf>1 && data > root->left->data)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    else if( bf<-1 && data< root->right->data)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    else 
        return root;
}

void main()
{
    struct tree *root=NULL;
	int choice,data,element,ans;
	printf("Enter 1 to insert\nEnter 2 for preorder traversal\nEnter 3 to delete an element\nEnter 4 to search an element\nEnter 5 to exit\n");
	while(1)
	{
		printf("****\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to insert: ");
				scanf("%d",&data);
				root = insert(root,data);
				break;
			case 2:
				printf("Inorder traversal\n");
				inorder(root);
				printf("\n");
				break;
			case 3:
				printf("Enter element to delete: ");
				scanf("%d",&element);
				root = deleteNode(root,element);
				break;
			/*case 4:
				printf("Enter element to search: ");
				scanf("%d",&element);
				ans=search(root,element);
				if(ans==1)
					printf("element found\n");
				else
					printf("element not found\n");
				break;*/
			case 4:
				exit(0);
				break;
			default:
				printf("Wrong choice\n");
				break;
		}
	}
    printf("\n");
}