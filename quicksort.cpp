//Quick sort
 
#include<iostream>
using namespace std;

void display(int ar[], int size){
	for(int i=0; i<size; i++)
		cout<<ar[i]<<" ";
	cout<<endl;
}

int partition(int ar[], int p, int r){
	int x, temp, i;
	x = ar[r];
	i = p-1;
	for(int j = p; j <= r-1; j++){
		if(ar[j] <= x){
			i++;
			swap(ar[i], ar[j]);
		}
	}
	swap(ar[i+1], ar[r]);
	return i+1;
}

void quick_sort(int ar[], int p, int r){
	if(p < r){
		int q = partition(ar, p, r);
		quick_sort(ar, p, q-1);
		quick_sort(ar, q+1, r);
	}
}

int main(){
	int a[] = {10,8,9,6,7,2,4,5,1,3};
	int size = 10;
	display(a,size);
	quick_sort(a, 0, size-1);
	display(a,size);
}
