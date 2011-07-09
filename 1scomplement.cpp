#include<iostream>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{

	int a = 50,i;
	for (i=0;i<32;i++)
		if(pow(2,i) > a)
			break;
	int n = pow(2,i) - 1;
	cout<<n<<endl;
	cout<<(~a)<<endl;
	cout<< ((a) ^ n)<<endl;
}
