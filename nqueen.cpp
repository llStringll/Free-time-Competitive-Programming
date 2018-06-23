#include<bits/stdc++.h>
using namespace std;

int isplcble(int i,int n,vector<int> *b){
	//if can be placed return value
	//else return -1
	int j=0;
	for(j=0;j<n;j++){
		//i,j is being considered here
		//ld sum should be i+j
		if(b[i][j]==1 || b[i][j]==-1)continue;
		bool col=true;
		for(int k=0;k<n;k++){
			if(b[k][j]==1){
				col=false;
				break;
			}
		}
		if(!col)continue;
		bool ld=true;
		int ldsum=i+j;
		bool rd1=true;
		bool rd2=true;
		for(int p=0;p<n;p++){
			for(int l=0;l<n;l++){
				if(p+l==ldsum && b[p][l]==1){
					ld=false;
					break;	
				}	
			}
			if(!ld)break;
		}
		if(!ld)continue;
		for(int p=i,l=j;p<n && l<n;p++,l++){
			if(b[p][l]==1){
				rd1=false;
				break;
			}
		}
		if(!rd1)continue;
		for(int p=i,l=j;p>=0 && l>=0;p--,l--){
			if(b[p][l]==1){
				rd2=false;
				break;
			}
		}
		if(!rd2)continue;
		if(col && ld && rd1 && rd2)
			return j;
	}
	if(j==n)return -1;
}

void solve(int n,vector<int> *b){
	for(int i=0;i<n;i++){
		int j=isplcble(i,n,b);
		if(j>=0){
			for(int k=0;k<n;k++){
				if(b[i][k]==1)b[i][k]=-1;
			}
			b[i][j]=1;
		}else{
			for(int k=0;k<n;k++)
				b[i][k]=0;
			i-=2;
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> b[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b[i].push_back(0);
		}
	}
	solve(n,b);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(b[i][j]==-1)b[i][j]=0;
			cout<<b[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
