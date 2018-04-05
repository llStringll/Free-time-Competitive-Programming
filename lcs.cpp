/*https://www.youtube.com/watch?v=Qf5R-uYQRPk*/
/*longest common (contiguous/discontiguous) subsequence from two strings,using dynamic programming("mem" is used for D.P.)*/
#include<bits/stdc++.h>
using namespace std;

int lcs(string a,string b,int la,int lb,vector<int> *mem){
  if(mem[la][lb]!=-1)return mem[la][lb];
  else{
    int res;
    if(la==0 || lb==0)res=0;
    else if(a[la-1]==b[lb-1])res=1+lcs(a,b,la-1,lb-1,mem);
    else{
      res=max(lcs(a,b,la-1,lb,mem),lcs(a,b,la,lb-1,mem));
    }
    mem[la][lb]=res;
    return res;
  }
}

int main(){
    string a;
    string b;
    cin>>a;
    cin>>b;
    vector<int> mem[a.length()+1];
    for(int i=0;i<=a.length();i++)
      for(int j=0;j<=b.length();j++)
        mem[i].push_back(-1);
    cout<<lcs(a,b,a.length(),b.length(),mem);
    return 0;
}
