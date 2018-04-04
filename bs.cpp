#include <bits/stdc++.h>
/*beautiful strings is the name of the question*/
using namespace std;

int calcli(int y){
  int l=0;
  while(y>0){
    l++;
    y/=10;
  }
  return l;
}

int strtoint(string s1){
  return atol(s1.c_str());
}

int func(string s,string s1,int i){
  int n=s.length();
  int x=strtoint(s1);
  //cout<<"x "<<x;
  int y=x+1;
  int ly=calcli(y);
  string s2;
  for(int k=i+1;k<=i+ly;k++){
    s2+=s[k];
  }
  int z=strtoint(s2);
  int chk=0;
  if(z==y && i+ly<n-1)
    chk=func(s,s2,i+ly);
  if(chk==1 || (z==y && i+ly==n-1) )return 1;
  if(z!=y || chk!=1)return 0;

  return 0;
}


string separateNumbers(string s) {
    for(int i=0;i<s.length()/2;i++){
    string s1;
    for(int j=0;j<=i;j++)
      s1+=s[j];
    int poss=func(s,s1,i);
    if(poss==1){
      return "YES "+s1;
    }
    else if(poss==0)continue;
  }
  return "NO";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        cout<<separateNumbers(s)<<"\n";
    }
    return 0;
}
