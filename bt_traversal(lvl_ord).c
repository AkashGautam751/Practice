#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left, *right;
};

void printlevelorder(struct node *root)
{
  int h=height(root);
  int i;
  for(i=1;i<=h;i++)
    printgivenlevel(root,i);
}

void printgivenlevel(struct node *root,int level)
{
  if(root==NULL)
    return;
  else if(level==1)
    printf("%d ",root->data);
  else if(level>1)
  {
    printgivenlevel(root->left,level-1);
    printgivenlevel(root->right,level-1);
  }
}

int height(struct node* root)
{
  if(root==NULL)
    return 0;
  else
  {
    int lheight=height(root->left);
    int rheight=height(root->right);

    if(lheight>rheight)
      return(lheight+1);
    else
    {
      return(rheight+1);
    }
  }

}

struct node *createnode(int data)
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

int main()
{
  struct node * root=createnode(1);
  root->left=createnode(2);
  root->right=createnode(3);
  root->left->left=createnode(4);
  root->left->right=createnode(5);

  printlevelorder(root);
}
