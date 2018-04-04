/*https://www.geeksforgeeks.org/maximum-subarray-size-subarrays-size-sum-less-k/*/
/*really good question*/
#include<bits/stdc++.h>
using namespace std;
int  main(){
  int n,k;
  cin>>n>>k;
  int a[n],s[n+1];
  s[0]=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    s[i+1]=s[i]+a[i];
  }

  int hi=n,lo=1,ans;
  while(hi>lo){
    int mid=(lo+hi)/2;
    int i=mid;
    for(i=mid;i<=n;i++){
      if(s[i]-s[mid-i]>k)break;
    }
    if(i==n+1){
      ans=mid;
      lo=mid+1;
    }
    else{
      hi=mid-1;
    }
  }
  cout<<ans;
  return 0;
}
