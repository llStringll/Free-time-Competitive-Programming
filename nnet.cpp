#include<bits/stdc++.h>

using namespace std;

int main(){
    int nlayers,minX,maxX;
    cin>>nlayers>>minX>>maxX;
    int w[nlayers],b[nlayers];
    for(int i=0;i<nlayers;i++){
        cin>>w[i]>>b[i];
    }
    
    int sp=0,nsp=0;//odd,even
    for(int j=minX;j<=maxX;j++){
        int x=j;
        for(int i=0;i<nlayers;i++){
            int a=w[i]*x+b[i];
            x=a;
        }
        
        (x%2==0)?nsp++:sp++;
        
    }
    
    cout<<nsp<<" "<<sp;
    
    return 0;
}