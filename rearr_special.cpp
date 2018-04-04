/*https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/*/
/*really nice question*/
#include<bits/stdc++.h>
using namespace std;

int part(int *a,int p,int r){
  int i=p-1;
  int hi=0;
  for(int j=p;j<=r;j++){
    if(a[j]<=hi){
      i++;
      int t=a[j];
      a[j]=a[i];
      a[i]=t;
    }
  }
  return i+1;
}

int main(){
  int n=9;
  int a[n]={-1, 2, -3, 4, 5, 6, -7, 8, 9};
  int par=part(a,0,n-1);

  for(int i=0;i<n;i++)//4   -3    5   -1    6   -7    2    8    9
    cout<<a[i]<<" ";

  cout<<"\n";
  for(int i=par;i<n;i++){
    if((i-par)%2==0){
      //swap a[i] with a[i-par]
      int t=a[i];
      a[i]=a[i-par];
      a[i-par]=t;
    }
  }

  for(int i=0;i<n;i++)//4   -3    5   -1    6   -7    2    8    9
    cout<<a[i]<<" ";

  return 0;
}
