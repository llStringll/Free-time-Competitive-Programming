/*Multiply large numbers*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,x,y;
    cin>>a>>b;
    x=(a>b)?a:b;
    y=(a<b)?a:b;
    int x2=x;
    vector<int> v,res;
    vector<int> :: iterator itr=v.begin();
    while(x2>0){
        v.push_back(x2%10);
        x2/=10;
    }
    //cout<<v[0];
    int carry=0;
    
    for(itr=v.begin();itr!=v.end();itr++){
        int prod=(*itr)*y + carry;
        int u_dig=prod%10;
        res.push_back(u_dig);
        carry=prod/10;
    }
    if(carry!=0)res.push_back(carry);
    int l=res.size();
    int resl[l];
    itr=res.begin();
    for(int i=l-1;i>=0;i--){
        resl[i]=(*itr);
        ++itr;
    }
    for(int i=0;i<l;i++){
        cout<<resl[i];
    }
    return 0;
}