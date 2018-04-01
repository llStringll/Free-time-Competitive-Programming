/*split the given array into two equal sum sub arrays*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n],s[n+1];
	s[0]=0;
	for(int i=0;i<n;i++){
		cin>>a[i];//1 2 3 4 5 5
		s[i+1]=a[i]+s[i];//0 1 3 6 10 15 20
	}

	int ri=0;
	int vc[n+1]={0};//1 if visited
	int mid=(n+1)/2;//3

	while(vc[mid]==0){
		int tempm=mid;//3
		if(s[mid]==s[n]-s[mid]){ri=mid-1;break;}
		else if(s[mid]>s[n]-s[mid]){
			mid--;
			vc[tempm]=1;
		}
		else{
			mid++;
			vc[tempm]=1;
		}
	}

	if(ri!=0){
		for(int i=0;i<=ri;i++)
			cout<<a[i];
	}else{
		cout<<"not possible";
	}

	return 0;
}