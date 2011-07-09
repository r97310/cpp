//Count sort

#include<iostream>
#include<cstring>
using namespace std;

void count_sort(int ar[], int b[], int size, int k=9){
	int c[k+1],j;
	memset(c, 0, k+1);
	for(j=1; j<=size; j++)
		c[ar[j]] += 1;
	
	for(j=1; j<=k; j++)
		c[j] += c[j+1];

	for(j=size; j>=0; j--){
		b[c[ar[j]]] = ar[j];
		c[ar[j]] -= 1;
	}
}

void display(int ar[], int size){
	for(int i=0; i<size; i++)
		cout<<ar[i]<<" ";
	cout<<endl;
}
int main(){
	int a[] = {0,1,8,9,6,7,2,4,5,1,3};
	int b[11];
	int size = 11;
	display(a,size);
	count_sort(a,b,size);
	display(a,size);
}
