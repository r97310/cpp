#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

int noOfCoins[60], lastCoin[60];

//k is the num of deno, n is the value for which deno is to be found
int findDeno(int deno[], int k, int n){
	int min, coin,i,j;
	//memset(noOfCoins, -1, n);
	
	/*for(i=0;i<4;i++)
		cout<<deno[i]<<" ";
	cout<<endl;
	for(i=0;i<=60;i++)
		cout<<noOfCoins[i]<<" ";
	*/
	noOfCoins[0] = 0;
	for(i=1;i<=n;i++){
		min = INT_MAX;
		for(j=1;j<=k;j++){
			if(deno[j] <= i && 1+noOfCoins[i-deno[j]] < min){
				min = 1+noOfCoins[i-deno[j]];
				coin = j; 
			}
		}
		noOfCoins[i] = min;
		lastCoin[i] = deno[coin];
	}
	return noOfCoins[n];
}

int main(){
	int deno[]={0,1,5,30,40},k=4,n=60;
	int res;
	res = findDeno(deno,k,n);
	for(int i=0;i<=60;i++){
		cout<<i<<" "<<noOfCoins[i]<<" "<<lastCoin[i]<<" "<<endl;
	}
	
}
