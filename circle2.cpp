#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main(){
    
    int np;
    cin>>np;
    
    double dist[np];
    
    for(int i=0;i<np;i++){
        long long int x,y;
        cin>>x>>y;
        dist[i] = sqrt(x*x + y*y);
    }
    
    int nr;
    cin>>nr;
    
    long long int r[nr];
    sort(dist,dist+np);
    
    int ans[nr];

    for(int i=0;i<nr;i++){
        cin>>r[i];
        
        int lo=0;
        int hi=np;
        
        while(hi>lo){
            int mid=(lo+hi)/2;
            if(r[i]<dist[mid]){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        ans[i] = lo;
    }
    
    for(int j=0;j<nr;j++){
        cout<<ans[j]<<"\n";
    }
    
    return 0;
}