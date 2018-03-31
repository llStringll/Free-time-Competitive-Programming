#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long int a[n];
    double p=1.0/n;
    double x=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        x=x*pow(a[i],p);
    }
    
    cout<<int(x)+1;//cant use ceil as it gives rounded off scientific notation
    //x^n > p
    
    return 0;
}