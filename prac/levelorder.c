#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};
struct tree* create()
{
    int x;
    printf("enter the data(-1 to stop)\n");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    struct tree* ptr=(struct tree*)malloc(sizeof(struct tree));
    ptr->data=x;
    printf("enter the left child of %d\n",x);
        ptr->left=create();
    printf("enter the right child of %d\n",x);
        ptr->right=create();
    return ptr;
}

void preorder(struct tree* t)
{
    static int s=0;
    if(t!=NULL)
    {
        printf("%d ",t->data);
        s+=t->data;
        printf("%d",s);
        preorder(t->left);
        preorder(t->right);
    }
}
void levelorder(struct tree* t,int level)
{
    if(t!=NULL && level >=0)
    {
        if(level == 0)
            printf("%d ",t->data);
        levelorder(t->left,level-1);
        levelorder(t->right,level-1);
    }
}
void main()
{

    struct tree* root=NULL;
    root=create();
    printf("\nThe preorder traversal of tree is:\n");
    preorder(root);
    /*printf("\nThe inorder traversal of tree is:\n");
    inorder(root);
    printf("\nThe postorder traversal of tree is:\n");
    postorder(root);
    */
   printf("\nlevel order\n");
   for(int i=0;i<4;i++)
   {
       levelorder(root,i);
   }
}
