/*https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/tree-counting-3/*/
#include<bits/stdc++.h>

using namespace std;

struct node{
    int d;
    struct node *l;
    struct node *r;
};

node *find(node *root,long int p){
    if(root==NULL)return NULL;
    if(p==root->d)return root;
    else if(find(root->l,p)!=NULL){
        return find(root->l,p);
    }else{
        return find(root->r,p);
    }
}

void add(node *root,long long int a,long long int p){
    node *prnt=find(root,p);
    if(prnt->l==NULL){
        prnt->l=new node;
        prnt->l->d=a;
        prnt->l->l=NULL;
        prnt->l->r=NULL;
    }
    else{
        prnt->r=new node;
        prnt->r->d=a;
        prnt->r->l=NULL;
        prnt->r->r=NULL;
    }
}

/*void disp(node *root){
    if(root==NULL)return;
    cout<<root->d;
    disp(root->l);
    disp(root->r);
}*/

int main(){
    int n,k,i;
    cin>>n>>k;
    long long int a[n],p[n-1];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n-1;i++){
        cin>>p[i];
    }
    
    node *root=new node;
    root->d=a[0];
    root->l=NULL;
    root->r=NULL;
    
    for(i=1;i<n;i++){
        add(root,a[i],p[i-1]);
    }
    
    //disp(root);
    
    
    return 0;
}