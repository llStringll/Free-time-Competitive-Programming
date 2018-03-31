#include<bits/stdc++.h>

using namespace std;

bool ifattack(int *result,int px,int py){
    cout<<"checking for "<<px<<" queen\n";
    int flag=0;
    for(int j=0;j<px;j++){//px is equal to nq
        if(result[j]==py || px+py==j+result[j] || px-py==j-result[j]){
            flag=1;
            break;
        }
    }
    if(flag==0)return true;
    else return false;
}


void placeit(int *result,int n,int nq){
    bool placed=false;
    cout<<"placing "<<nq<<" queen\n";
    int init;
    if(result[nq]==n-1){
        placeit(result,n,nq-1);
        init=0;
    }
    else init=result[nq]+1;
    for(int i=init;i<n;i++){
        bool place=ifattack(result,nq,i);
        if(place){
            result[nq]=i;
            placed=true;
            break;
        }else{
            placed=false;
        }
    }
    if(placed && nq==n-1) return;
    if(placed){
        placeit(result,n,nq+1);
    }else{
        placeit(result,n,nq-1);
    }
}


int main(){
    int n;
    cin>>n;
    int result[n];//to store coordinate of queens
    
    
    result[0]=0;//answer is (index,value)
    for(int i=1;i<n;i++){
        result[i]=-1;
    }
    placeit(result,n,1);
    
    for(int i=0;i<n;i++){
        cout<<i<<","<<result[i]<<endl;
    }
    
    return 0;
}