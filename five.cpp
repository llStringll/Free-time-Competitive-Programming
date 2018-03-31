#include<bits/stdc++.h>

using namespace std;

int main(){
    long int r,n,ans;
    cin>>r;
    
    long long int arr[25],cnt[25];
    arr[0]=1,cnt[0]=0;
    for(int i=1;i<25;i++){
        cnt[i]=cnt[i-1]*5+1;
        arr[i]=arr[i-1]*5;
    }
    
    while(r--){
        cin>>n;
        ans=0;
        
        while(n>0){
            int i;
            for(i=1;cnt[i]<=n;i++);
                if(i!=1)i--;
                ans+=arr[i];
                n-=cnt[i];
        }
        
        cout<<ans<<"\n";
    }
    
    return 0;
}