#include<bits/stdc++.h>

using namespace std;

int main(){
    string a;
    getline(cin,a);
    cout<<a;
    char c='.';
    int l=0;
    while(c!='\0'){
        c=a[l];
        l++;
    }
    l--;
    cout<<endl<<l;
    
    sort(a.begin(),a.end());
    cout<<a;
    int max=0;
    int count = 1;
    for(int i=0;i<l-1;i++){
        if(a[i]==a[i+1]){
            count++;
        }else{
            (max>count)?max=max:max=count;
            count=1;
        }
    }
    
    cout<<max;
    
    return 0;
}