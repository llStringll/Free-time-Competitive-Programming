#include<bits/stdc++.h>
#define PI 3.14159265358979323846264338327950288

using namespace std;

int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int flag=0;
        pair<int,int> arr[n];
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            arr[i] = make_pair(x,y);
        }

        for(int i=0;i<n-2;i++){
            pair<double,double> vec1 = make_pair(arr[i+1].first-arr[i].first,arr[i+1].second-arr[i].second);
            pair<double,double> vec2 = make_pair(arr[i+2].first-arr[i+1].first,arr[i+2].second-arr[i+1].second);

            //cout<<vec1.first<<","<<vec1.second<<endl;
            //cout<<vec2.first<<","<<vec2.second<<endl;

            double d1 = sqrt( vec1.first*vec1.first + vec1.second*vec1.second );
            double d2 = sqrt( vec2.first*vec2.first + vec2.second*vec2.second );

            //cout<<"dist: "<<d1<<","<<d2<<endl;

            double cosang = (vec1.first*vec2.first + vec1.second*vec2.second )/(d1*d2);

            //cout<<cosang;

            int ang = acos(cosang) * 180/PI;

            //cout<<"\nangle: "<<ang;
            if(ang<=45)flag=0;
            else { flag++; }
        }

        string rem;
        
        if(flag==0){
            rem="yes";
            cout<<"yes "<<rem;
        }
        else{
            //set rem here
            cout<<"no "<<rem;
        }
        
    }
    
    return 0;
}