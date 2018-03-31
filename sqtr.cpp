#include<bits/stdc++.h>

using namespace std;

int main(){
    int ntr;
    cin>>ntr;
    int tr[ntr];
    for(int i=0;i<ntr;i++)
        cin>>tr[i];
    
    int str[ntr];
    str[0]=tr[0];
    for(int i=1;i<ntr;i++){
        str[i]=str[i-1]+tr[i];
    }
    
    int ntar;
    cin>>ntar;
    int tar[ntar];
    for(int i=0;i<ntar;i++){
        cin>>tar[i];
        
        int ans;
        int hi=ntr,lo=0;
        while(hi>lo){
            int mid=(hi+lo)/2;
            if(tar[i]<=str[mid]){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        ans=++lo;
        if(tar[i]>str[ntr-1]){
            ans=-1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}