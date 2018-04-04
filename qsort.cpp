/*quick sort*/
#include<bits/stdc++.h>

using namespace std;

int part(int *a,int p,int r){//a[] = {10, 80, 30, 90, 40, 50, 70}
  int i=p-1;
  int hi=a[r];
  for(int j=p;j<r;j++){
    if(a[j]<=hi){
      i++;
      int t=a[i];
      a[i]=a[j];
      a[j]=t;
    }
  }
  int t=a[i+1];
  a[i+1]=a[r];
  a[r]=t;
  return i+1;
}

void qsort(int *a,int p,int r){
  if(p<r){
    int q=part(a,p,r);//a 0 n-1
    qsort(a,p,q-1);
    qsort(a,q+1,r);
  }
}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];

  qsort(a,0,n-1);

  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  return 0;
}
