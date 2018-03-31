#include<bits/stdc++.h>

using namespace std;

int min(int a,int b){
   if(a<b)return a;
    else return b;
}

int main(){
    int n,c;
    cin>>n>>c;
    queue<int> q1,q2;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        q1.push(v);
        q2.push(i+1);
    }
    
    
    vector<int> stor1,stor2;
    vector<int>::iterator itr,itr2;
    
    for(int j=0;j<c;j++){
        stor1.clear();
        stor2.clear();
        int siz=min(c,q1.size());
        for(int k=0;k<siz;k++){
            stor1.push_back(q1.front());
            q1.pop();
            stor2.push_back(q2.front());
            q2.pop();
        }
        /*cout<<"vector is: ";
        for(itr=stor1.begin(),itr2=stor2.begin();itr2!=stor2.end(),itr!=stor1.end();itr2++,itr++){
            cout<<"=>"<<*itr<<","<<*itr2;
        }
        cout<<"\n";
        cout<<"\n";
        cout<<j+1<<" iteration\n";*/
        int max=*(stor1.begin());
        //cout<<"let max be:"<<max<<endl;
        itr=stor1.begin();
        vector<int>::iterator posi=itr,pos=stor2.begin(),ans=pos;
        for(itr=stor1.begin(),pos=stor2.begin();itr!=stor1.end(),pos!=stor2.end();pos++,itr++){
            if(*itr>max){
                max=*itr;
                //cout<<"\npos is:"<<*pos;
                ans=pos;
                posi=itr;
            }
        }
        
        cout<<*ans<<" ";
        
        stor1.erase(posi);
        //cout<<"ele erased";
        stor2.erase(ans);
        //cout<<"index erased";
        
        for(itr=stor1.begin(),itr2=stor2.begin();itr!=stor1.end(),itr2!=stor2.end();itr++,itr2++){
            //cout<<"\npushing back";
            int val;
            if(*itr>0){val=*itr-1;}
            else val=0;
            q1.push(val);
            //cout<<*itr<<"\npushed back";
            q2.push(*itr2);
        }
    }
    
    
    return 0;
}