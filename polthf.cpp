#include<bits/stdc++.h>

using namespace std;

int main(){//can catch -- only in row, <=K units, 1P~1T
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        char grid[n][n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='P'){
                    //cout<<"P at:"<<i<<","<<j<<endl;
                    for(int l=j-k;l<=j+k;l++){
                        if(l<0)l=0;
                        //cout<<"l is "<<l<<endl;
                        if(grid[i][l]=='T'){
                            //cout<<"t at "<<i<<","<<l<<endl;
                            ans++;
                            grid[i][l]='C';
                            break;
                        }
                        if(l==n-1)break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}