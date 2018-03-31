#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int n_tc;
    cin>>n_tc;
    int n_bs[n_tc];
    
    vector <int> g_ans[n_tc];
    
    for(int i=0;i<n_tc;i++){
        cin>>n_bs[i];
        int size = n_bs[i];
        int cities[size][2];
        for(int j=0;j<size;j++){
            cin>>cities[j][0];
            cin>>cities[j][1];
        }
        
        int n_rcs;
        cin>>n_rcs;
        int rcs[n_rcs];
        for(int k=0;k<n_rcs;k++){
            cin>>rcs[k];
        }

        int ans[n_rcs];
        
        
        for(int l=0;l<n_rcs;l++){
            ans[l]=0;
            for( int m=0;m<size;m++){
                if(rcs[l]>=cities[m][0] && rcs[l]<=cities[m][1]){
                    ans[l]++;
                }
            }
            cout<<"=>"<<ans[l]<<"\n";
            g_ans[i].push_back(ans[l]);
        }
        
    }
    
    
    for(int i=0;i<n_tc;i++){
        vector <int> :: iterator itr;
        cout<<"\n";
        for(itr = g_ans[i].begin();itr!=g_ans[i].end();itr++){
            cout<<*itr<<" ";
        }
    }
    
    return 0;
}