#include<bits/stdc++.h>
/*to find minimum and maximum sum of an array after removing 1 element*/
using namespace std;

int main(){
    int size;
    cin>>size;
    int n[size];
    for(int i=0;i<size;i++){
        cin>>n[i];
    }
    
    sort(n,n+size);
    int min=0,max=0;
    for(int i=1;i<size;i++){
        max+=n[i];
        min+=n[i-1];
    }
    
    cout<<min<<" "<<max;
    
    return 0;
}