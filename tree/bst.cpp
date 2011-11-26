//bst
//same as binarytreesort.cpp with added parent data in every node

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define TRUE 1
#define FALSE 0

struct btreenode{
	int data;
	struct btreenode *right;
	struct btreenode *left;
	struct btreenode *parent;
};

#define NODE struct btreenode

NODE* createNewNode(int num) {
	NODE *sr;
	sr = (NODE*)malloc(sizeof(NODE));		
	(sr)->left=NULL;
	(sr)->data=num;
	(sr)->right=NULL;
	(sr)->parent=NULL;
	return sr;
}

void insert(NODE **sr,int num){
	if(*sr == NULL) {
		*sr = createNewNode(num);
	} else if(num <= (*sr)->data) {
		//cout<<"\nsr left::"<<(*sr)->data;
		if ((*sr)->left == NULL) {
			NODE *temp = createNewNode(num);
			(temp)->parent = *sr;
			(*sr)->left = temp;
		} else
			insert(&((*sr)->left),num);
	}
	else {
		//cout<<"\nsr right::"<<(*sr)->data;
		if ((*sr)->right == NULL) {
			NODE *temp = createNewNode(num);
			(temp)->parent = *sr;
			(*sr)->right = temp;
		} else
			insert(&((*sr)->right),num);
	}
	
	return;
}

void inorder(NODE *sr){
	if(sr!=NULL)
	{
		inorder(sr->left);
		printf("%d ",sr->data);
		inorder(sr->right);
	}
	else
		return;
}

void postorder(NODE *sr){
	if(sr!=NULL)
	{
		postorder(sr->right);
		postorder(sr->left);
		printf("%d ",sr->data);
	}
	else
		return;
}

int search(NODE *sr, int num) {
	if (sr != NULL) {
		if (sr->data == num) {
			cout<<"Found:: "<<num<<endl;
			return num;
		}
			
		else if (num <= sr->data)
			search(sr->left, num);
		else 
			search(sr->right, num);
	} else
		return -1;
}

int main() {
	NODE *bt;
	int req,i=0,num,a[10],no,index;

	bt=NULL;

	while(i < 10){
		printf("\nEnter value to be inserted: ");
		scanf("%d",&a[i]);
		insert(&bt,a[i]);
		i++;
	}

	printf("\n\nInorder== > \n\n");
	inorder(bt);
	printf("\n\nPostOrder== >\n\n");
	postorder(bt);
	cout<<endl;
	index=search(bt, 30);
	cout<<"=>"<<index<<endl;
	index=search(bt, 60);
	cout<<"=>"<<index<<endl;
	index=search(bt, 56);
	cout<<"=>"<<index<<endl;
	cout<<"\n";
}
