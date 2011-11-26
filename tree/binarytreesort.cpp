//Binary search tree

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define TRUE 1
#define FALSE 0

struct btreenode{
	struct btreenode *rightchild;
	int data;
	struct btreenode *leftchild;
};

void insert(struct btreenode **sr,int num){
	if(*sr==NULL)
	{
		*sr=(btreenode*)malloc(sizeof(struct btreenode));

		(*sr)->leftchild=NULL;
		(*sr)->data=num;
		(*sr)->rightchild=NULL;
		return;
	}
	else
	{
		if(num < (*sr)->data)
			insert(&((*sr)->leftchild),num);
		else
			insert(&((*sr)->rightchild),num);
	}
	return;
}

void inorder(struct btreenode *sr){
	if(sr!=NULL)
	{
		inorder(sr->leftchild);
		printf("%d ",sr->data);
		inorder(sr->rightchild);
	}
	else
		return;
}

void postorder(struct btreenode *sr){
	if(sr!=NULL)
	{
		postorder(sr->rightchild);
		postorder(sr->leftchild);
		printf("%d ",sr->data);
	}
	else
		return;
}

int main()
{
	struct btreenode *bt;
	int req,i=0,num,a[10],no;

	bt=NULL;

	while(i < 5){
		printf("\nEnter value to be inserted: ");
		scanf("%d",&a[i]);
		insert(&bt,a[i]);
		i++;
	}

	printf("\n\nSorted Binary tree in ascending order== > \n\n");
	inorder(bt);
	printf("\n\nSortred binary tree in descending order== >\n\n");
	postorder(bt);
}
