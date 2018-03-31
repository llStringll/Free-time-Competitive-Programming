/*https://www.codechef.com/problems/NUMBGAME*/
#include<bits/stdc++.h>

using namespace std;

void swap(char &s0,char &sj){
    char t=s0;
    s0=sj;
    sj=t;
}

bool isdiv(int num,int m){
    if(num%m==0) return true;
    else return  false;
}

int main(){
    int t;
    cin>>t;
    
    
    while(t--){
        string s;
        int m;
        
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin>>s;
        cin>>m;

        int l=s.length();

        string arr[l];//poss

        for(int j=1;j<=l-1;j++){
            for(int i=1;i<l;i++){
                arr[j-1][i-1]=s[i];
            }
            swap(s[0],s[j]);
        }

        for(int i=1;i<l;i++){
            arr[l-1][i-1]=s[i];
        }

        int ans;

        for(int i=0;i<l;i++){
            string si = arr[i];
            stringstream geek(si);
            int x = 0;
            geek >> x;
            cout << "Value of x : " << x;
            if(l>=3){
                if(isdiv(x,m)){//chk div. of possibilities with 4...if any one gives yes, answer is l else 0
                    ans=l;
                    break;
                }else ans=0;
            }else{
                cout<<"for 2 or 1 digit: "<<x<<" ";
                if(isdiv(x,m)){
                    ans=1;
                    break;
                }else ans=0;
            }
        }

        cout<<ans<<"\n";
    }
    
    return 0;
}