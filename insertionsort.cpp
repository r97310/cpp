// Insertion sort

#include<iostream>
using namespace std;

void insertion_sort(int a[], int size){
	int i, j, key;
	for(j=1; j<size; j++){
		key = a[j];
		i = j-1;
		while(i>=0 && a[i]>key){
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}

void display(int ar[], int size){
	for(int i=0; i<size; i++)
		cout<<ar[i]<<" ";
	cout<<endl;
}
int main(){
	int a[] = {10,8,9,6,7,2,4,5,1,3};
	int size = 10;
	display(a,size);
	insertion_sort(a,size);
	display(a,size);
}
