#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int main(){
	char str[100000];
	double f = -24.567;
	string s = "";
	
	int i, count=0;
	

	if(f < 0){
		str[count++] = '-';
		f *= -1;
		cout<<f<<endl;
	}

	long long l = floor(f);
	cout<<l<<endl;

	cout<<f-l<<endl;
}
