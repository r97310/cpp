#include<iostream>
#include<string>
#include<vector>
#include<cstdio>

using namespace std;	

long long combination(int n, int a){
	int b,i;
	long long x=1,y=1,z=1;
	b = n-a;
	if (a==0 || a==n)
		return 1;
	if (a==1)
		return n;
	if (a<=b){
		for(i=0;i<a;i++)
			x*=n-i;
		for(i=2;i<=a;i++)
			y*=i;
	}
	else{
		for(i=0;i<b;i++)
			x*=n-i;
		for(i=2;i<=b;i++)
			y*=i;
	}
	return x/y;
}

int main(){
	cout<<combination(5,3)<<endl;;
}
