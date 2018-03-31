/*Number of subarrays whose minimum and maximum are same*/
#include<bits/stdc++.h>
using namespace std;

int func(int *arr,int n){
	int ans=0;
	for(int i=0;i<n;i++){
		int count=0;

		while(arr[i]==arr[i+count])
			count++;

		ans+=(count*(count+1))/2;

		i+=count-1;
	}
	return ans;
}

int main(){
	int n=6;
	int arr[n]={2,4,5,3,3,3};
	int ans=func(arr,n);
	cout<<ans;
	return 0;
}