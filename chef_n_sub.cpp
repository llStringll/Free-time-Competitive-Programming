/*https://www.codechef.com/problems/CHEFARRP*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        long long int a[n],s[n+1],p[n+1];
        s[0]=0;
        p[0]=1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s[i+1]=s[i]+a[i];
            p[i+1]=p[i]*a[i];
        }
        int c=0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<=i;j++){
                if( s[i]-s[j]==p[i]/p[j] )
                    c++;
            }
        }
        cout<<c<<"\n";
    }
    return 0;
}