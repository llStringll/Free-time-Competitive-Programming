#include<bits/stdc++.h>

using namespace std;

struct node{
    int d;
    struct node *l;
    struct node *r;
};

void add(int d,node *root){
    if(d<=root->d && root->l==NULL){
        root->l=new node;
        root->l->d=d;
        root->l->l=NULL;
        root->l->r=NULL;
        return;
    }if(d<=root->d && root->l!=NULL)add(d,root->l);
    if(d>root->d && root->r==NULL){
        root->r=new node;
        root->r->d=d;
        root->r->l=NULL;
        root->r->r=NULL;
        return;
    }if(d>root->d && root->r!=NULL)add(d,root->r);
}

int height(node *root){
    if(root==NULL)return 0;
    else if(root->l==NULL && root->r==NULL)return 1;
    else return (1+max(height(root->l),height(root->r)));
}

int findlca(node *root,int x,int y){
    if(root==NULL)return -1;
    if(root->d==x || root->d==y)return root->d;
    else{
        int i=findlca(root->l,x,y);
        int j=findlca(root->r,x,y);
        if(i!=-1 && j!=-1)return root->d;
        if(i==-1 && j!=-1)return j;
        if(i!=-1 && j==-1)return i;
        if(i==-1 && j==-1)return -1;
    }
}

node *find(node *root,int lca){
    if(root->d==lca)return root;
    else if(lca<root->d) return(find(root->l,lca));
    else return(find(root->r,lca));
}

int findgr8(node *lcap,int bignum){
    if(bignum==lcap->d)return bignum;
    if(bignum>lcap->d)return findgr8(lcap->r,bignum);
    else if(bignum<lcap->d)return lcap->d;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    node *root=new node;
    root->d=a[0];
    root->l=NULL;
    root->r=NULL;
    
    for(int i=1;i<n;i++){
        add(a[i],root);//creating a bst
    }

    int h=height(root);
    cout<<"h:"<<h<<"\n";
    
    int x,y;
    cin>>x>>y;
    int lca=findlca(root,x,y);
    cout<<"lca:"<<lca<<"\n";
    
    int bignum=(x>y)?x:y;
    node *lcap=new node;
    lcap=find(root,lca);
    cout<<"data at lcap:"<<lcap->d<<"\n";
    int gr8er=findgr8(lcap,bignum);
    
    cout<<"gr8er:"<<gr8er<<"\n";
    
    return 0;
}