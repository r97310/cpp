// Heap sort
// not considering the first element in the array

#include<iostream>
using namespace std;

#define PARENT(i) i/2
#define LEFT(i) 2*i
#define RIGHT(i) 2*i+1

int heap_size;
int size = 10;

void max_heapify(int a[], int i){
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest;
	
	if(l <= heap_size && a[l] > a[i])
		largest = l;
	else
		largest = i;

	if(r <= heap_size && a[r] > a[largest])
		largest = r;
	
	if(largest != i){
		swap(a[i], a[largest]);
		max_heapify(a, largest);
	}
}

void build_max_heap(int a[]){
	heap_size = size;
	for(int i=size/2; i>0; i--){
		max_heapify(a, i);
	}
}

void heap_sort(int a[]){
	build_max_heap(a);
	for(int i=size; i>0; i--){
		swap(a[1], a[i]);
		heap_size--;
		max_heapify(a, 1);
	}
}

void display(int ar[], int size){
	for(int i=1; i<size+1; i++)
		cout<<ar[i]<<" ";
	cout<<endl;
}

int main(){
	int a[] = {-1,10,8,9,6,7,2,4,5,1,3};
	display(a,size);
	heap_sort(a);
	display(a,size);
}
