#include<bits/stdc++.h>

using namespace std;

struct tree{
    long long int data;
    struct tree *l,*r;
};

void add(long long int ele,tree *root){
    if(ele<=root->data && root->l!=NULL)add(ele,root->l);
    if(ele<=root->data && root->l==NULL){
        root->l=new tree;
        root->l->data=ele;
        root->l->l=NULL;
        root->l->r=NULL;
        return;
    }
    
    if(ele>root->data && root->r!=NULL)add(ele,root->r);
    if(ele>root->data && root->r==NULL){
        root->r=new tree;
        root->r->data=ele;
        root->r->l=NULL;
        root->r->r=NULL;
        return;
    }
    
}

long long int height(tree *root){
    if(root==NULL)return 0;
    else if(root->l==NULL && root->r==NULL)return 1;
    else return (1+max(height(root->l),height(root->r)));
}

int main(){
    long long int n,i=0;
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    
    tree *root=new tree;
    root->data=a[0];
    root->l=NULL;
    root->r=NULL;
    for(i=1;i<n;i++){
        add(a[i],root);
    }
    
    cout<<height(root);
    
    return 0;
}