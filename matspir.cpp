#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    int m[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>m[i][j];
        }
    }
    
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    int x_u=x-1,y_u=y-1,x_l=0,y_l=0;
    int xyflag=1,xinflag=0,yinflag=0;
    int itrx=0,itry=-1;
    while( x_u!=x_l && y_u!=y_l ){
        
        if(xyflag==0){
            
            if(xinflag==0){
                itrx++;//change here
                while(itrx<=x_u){
                    cout<<m[itrx][itry]<<",";
                    itrx++;
                }
                itrx--;
                x_l++;
                xinflag=1;
                
            }else{
                itrx--;//change here
                while(itrx>=x_l){
                    cout<<m[itrx][itry]<<",";
                    itrx--;
                }
                itrx++;
                x_u--;
                xinflag=0;
            }
        
            xyflag=1;
            
        }else{
            
            if(yinflag==0){
                itry++;//change here
                while(itry<=y_u){
                    cout<<m[itrx][itry]<<",";
                    itry++;
                }
                itry--;
                if(itry!=y-1)y_l++;
                yinflag=1;
                
            }else{
                itry--;//change here
                while(itry>=y_l){
                    cout<<m[itrx][itry]<<",";
                    itry--;
                }
                itry++;
                y_u--;
                yinflag=0;
            }
            
            xyflag=0;
        }
    }
    
    return 0;
}