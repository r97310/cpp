//Binary search tree

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define TRUE 1
#define FALSE 0

struct dll{
	struct dll *prev;
	struct dll *next;
	int data;
};
//struct dll *list;

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
		if(num< (*sr)->data)
			insert(&((*sr)->leftchild),num);
		else
			insert(&((*sr)->rightchild),num);
	}
	return;
}

void insertdll(int num, struct dll *list){

	if(list==NULL)
	{	
		list = new (struct dll);
		(list)->prev=list;
		(list)->data=num;
		(list)->next=list;
		return;
	}
	else
	{
		struct dll *temp = new (struct dll);
		struct dll *in = new (struct dll);
		temp = list;
		while(temp->next != list)
			temp = temp->next;

		in->data = num;
		temp->next = in;
		list->prev = in;

		in->prev = temp;
		in->next = list;
				
	}
	return;
}

void inorder(struct btreenode *sr, struct dll *list){

	if(sr!=NULL)
	{
		inorder(sr->leftchild, list);
		printf("%d ",sr->data);
		insertdll(sr->data, list);
		inorder(sr->rightchild, list);
	}
	else
		return;
}

int main()
{
	struct btreenode *bt;

	int req,i=0,num,a[10],no;

	bt=NULL;
	struct dll *list= NULL;
	list = NULL;
	while(i < 5){
		printf("\nEnter value to be inserted: ");
		scanf("%d",&a[i]);
		insert(&bt,a[i]);
		i++;
	}

	printf("\n\nSorted Binary tree in ascending order== > \n\n");
	inorder(bt, list);

	struct dll *n = new (struct dll);
	n = list;
	cout<<endl<<list;
	/*while(n->next != list){
		cout<<n->data<<" -> ";
		n = n->next;
	}*/
	//cout<<n->data;
}
