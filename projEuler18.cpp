#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//maximum sum triangle
int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector <int> arr[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                int x;
                cin>>x;
                arr[i].push_back(x);
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<arr[i].size();j++){
                int req=max(arr[i+1][j],arr[i+1][j+1]);
                arr[i][j]+=req;
            }
        }

        cout<<arr[0][0]<<endl;
    }
    return 0;
}