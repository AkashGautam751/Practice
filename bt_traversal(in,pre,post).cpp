#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node* left,*right;
};

void printinorder(node* temp)
{
  if(temp==NULL)
    return;

  printinorder(temp->left);
  cout<<temp->data<<" ";
  printinorder(temp->right);
}

void printpreorder(node* temp)
{
  if(temp==NULL)
    return;

  cout<<temp->data<<" ";
  printpreorder(temp->left);
  printpreorder(temp->right);
}

void printpostorder(node* temp)
{
  if(temp==NULL)
    return;

  printpostorder(temp->left);
  printpostorder(temp->right);
  cout<<temp->data<<" ";
}

node* createnode(int data)
{
  node *temp=new node;
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

int main()
{
  node *root=createnode(1);
  root->left=createnode(2);
  root->right=createnode(3);
  root->left->left=createnode(4);
  root->left->right=createnode(5);

  cout<<"INODER:";
  printinorder(root);
  cout<<endl<<"PREORDER:";
  printpreorder(root);
  cout<<endl<<"POSTORDER:";
  printpostorder(root);
}
