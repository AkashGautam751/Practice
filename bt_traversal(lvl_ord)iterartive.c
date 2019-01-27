#include<stdio.h>
#include<stdlib.h>
#define m 500
struct node
{
  int data;
  struct node *left,*right;
};

struct node** createqueue(int *, int *);
void enqueue(struct node **, int *, struct node *);
struct node *dequeue(struct node **, int *);

void printlevelorder(struct node* root)
{
  int rear,front;
  struct node **queue=createqueue(&front,&rear);
  struct node *temp=root;
  while(temp)
  {
    printf("%d ",temp->data);
    if(temp->left)
      enqueue(queue,&rear,temp->left);

    if(temp->right)
      enqueue(queue,&rear,temp->right);

    temp= dequeue(queue,&front);
  }
}

struct node** createqueue(int *front,int *rear)
{
  struct node** queue=(struct node**)malloc(sizeof(struct node*)*m);
  *rear=*front=0;

  return queue;
}

void enqueue(struct node** queue,int *rear,struct node *nnode)
{
  queue[*rear]=nnode;
  (*rear)++;
}

struct node *dequeue(struct node** queue,int *front)
{
  (*front)++;
  return queue[*front-1];
}

struct node *createnode(int data)
{
  struct node* temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->right=NULL;
  temp->left=NULL;
  return temp;
}

int main()
{
  struct node *root=createnode(1);
  root->left=createnode(2);
  root->right=createnode(3);
  root->left->left=createnode(4);
  root->left->right=createnode(5);

  printlevelorder(root);
}
