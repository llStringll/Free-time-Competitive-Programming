#include<bits/stdc++.h>
using namespace std;

int compare(int *pa,int *pb){
	int diff[3];
	for(int i=0;i<3;i++){
		diff[i]=pa[i]-pb[i];
	}
	sort(diff,diff+3);
	if( (diff[0]==0 && diff[2]==0) || (diff[0]<0 && diff[2]>0) )return -1;
	else if( (diff[0]>0 && diff[2]>0) || (diff[0]==0 && diff[2]>0) )return 0;
	else return 1;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int p[3][3];
		cin>>p[0][0]>>p[0][1]>>p[0][2];
		cin>>p[1][0]>>p[1][1]>>p[1][2];
		cin>>p[2][0]>>p[2][1]>>p[2][2];

		int a=compare(p[0],p[1]);
		int b=compare(p[1],p[2]);
		int c=compare(p[2],p[1]);

		if(a!=-1 && b!=-1 && c!=-1)cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}