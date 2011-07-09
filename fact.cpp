#include<iostream>
#include<string>
#include<vector>
#include<cstdio>

using namespace std;

long long fact(int n){
	int i;long long f=1;
	for (i=2;i<=n;i++)
		f*=i;
	return f;
}

int main(){
	cout<<fact(5)<<endl;	
}
