#include<bits/stdc++.h>
/*codechef kithen time table*/
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int ta[n];
    int tr[n];
    for(int i=0;i<n;i++)
      cin>>ta[i];
    for(int i=0;i<n;i++)
      cin>>tr[i];

    int c=0;
    if(tr[0]<=ta[0])
      c++;
    for(int i=1;i<n;i++){
      if(tr[i]<=ta[i]-ta[i-1]){
        c++;
      }
    }
    cout<<c<<"\n";
  }
  return 0;
}
