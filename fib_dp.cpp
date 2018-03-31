#include<bits/stdc++.h>
using namespace std;
//1 1 2 3 5 8 13
//1 2 3 4 5 6 7
int fib(int n,vector <int> v){
	if(n<=2)return 1;
	else {
		if(n<v.size())return v[n-1];
		else{
			int f=fib(n-1,v)+fib(n-2,v);
			v.push_back(f);
			return f;
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector <int> v;
	v.push_back(1);
	v.push_back(1);
	cout<<fib(n,v);
	return 0;
}