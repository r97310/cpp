#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

class node{
	public:
	node *next;
	int data;
};

void print(node *p){
	printf("in print(), pointer = %u\n", p);
	//printf("in print(), pointer = %u\n", *p);

	p = new node;
	p->data = 25;
	printf("in print(), pointer = %u\n", p);
	printf("in print(), pointer = %u\n", p->data);
}

int main(){
	//int *p, k;
	//p = &k;
	//k=10;
	node *p, *temp;
	p = NULL;
	

	printf("p = %u\n", p);
	
	print(p);

	printf("*p = %d\n", p);
	//printf("*p->data = %d\n", p->data);
	//free(temp);
	//free(p);
}	
