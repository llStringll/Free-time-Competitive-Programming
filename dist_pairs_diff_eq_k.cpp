/*calculate the number of distinct pairs in an array for which difference equals some k*/
/*see this only if cant get the code -- https://www.geeksforgeeks.org/count-pairs-difference-equal-k/*/
#include<bits/stdc++.h>

using namespace std;

int rem(int *arr,int n){
	int j=0;
	for(int i=0;i<n;i++)
		if(arr[i]!=arr[i+1])
			arr[j++]=arr[i];

	arr[j]=arr[n-1];
	return ++j;
}

bool search(int *arr,int init,int n,int a){
	int hi=n,lo=init;
	int flag=0;
	while(lo<hi){
		int mid=(lo+hi)/2;
		if(arr[mid]==a){flag++;break;}
		else if(arr[mid]<a)lo=mid+1;
		else hi=mid;
	}
	if(flag==0)return false;
	else return true;
}

int main(){
	int n,k,count=0;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	
	n=rem(arr,n);

	//a-b=k,a=k+b

	for(int i=0;i<n-1;i++){
		int a=k+arr[i];//b=arr[i]
		if(search(arr,i+1,n,a))
			count++;
	}

	cout<<count;

	return 0;
}