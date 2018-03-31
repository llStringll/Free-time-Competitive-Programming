/*find Kth largest sum of all subarrays of an array*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int sum[n+1];
	sum[0]=0;
	for(int i=0;i<n;i++){
		sum[i+1]=sum[i]+arr[i];
	}
	int  m=n*(n+1)/2;
	int ss[m],ct=0;
	for(int i=1;i<n+1;i++){
		for(int j=0;j<i;j++){
			ss[ct++]=sum[i]-sum[j];
		}
	}
	sort(ss,ss+m);
	cout<<ss[m-k];


	return 0;
}