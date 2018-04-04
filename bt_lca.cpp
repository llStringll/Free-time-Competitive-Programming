#include<bits/stdc++.h>
using namespace std;

struct node{
  int a;
  struct node *l;
  struct node *r;
};

int *lca(node *root,int x,int y){
  if(root==NULL)return NULL;
  int *rr=NULL,*rl=NULL;
  if(root->l==NULL && root->r==NULL)return NULL;
  if(root->l->a==x || root->l->a==y)rl=&(root->l->a);
  if(root->r->a==x || root->r->a==y)rr=&(root->r->a);
  if(rl==NULL)rl=lca(root->l,x,y);
  if(rr==NULL)rr=lca(root->r,x,y);

  if(rl==NULL && rr==NULL)return NULL;
  if(rl==NULL && rr!=NULL)return rr;
  if(rl!=NULL && rr==NULL)return rl;
  if(rl!=NULL && rr!=NULL)return &(root->a);
}

int main(){
  node *root=new node;
  root->a=1;
  root->l=new node;
  root->r=new node;
  root->l->a=2;
  root->l->l=new node;
  root->l->r=new node;
  root->l->l=NULL;
  root->l->r=NULL;
  root->r->a=3;
  root->r->l=new node;
  root->r->l->a=4;
  root->r->l->l=new node;
  root->r->l->l=NULL;
  root->r->l->r=new node;
  root->r->l->r=NULL;
  root->r->r=new node;
  root->r->r->a=5;
  root->r->r->l=new node;
  root->r->r->l=NULL;
  root->r->r->r=new node;
  root->r->r->r=NULL;

  int x,y;
  cin>>x>>y;
  if(root->a==x || root->a==y)
    cout<<root->a;
  else
    cout<<*(lca(root,x,y));

  return 0;
}
