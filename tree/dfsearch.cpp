#include<iostream>
#include<climits>
#include<string>
#include<queue>
#include<cstdlib>
#include<cstring>

#define MAX 10001
#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

int dist[MAX], parent[MAX];
int color[MAX];

class node {
	public:
		int vertex;
		int dist;
		node *next;
	node(){
		vertex = dist = 0;
	}
};
node *list[MAX];
int times;

void dfs_visit(int u){
	times = times+1;
	dist[u] = times;
	color[u] = GREY;

	node *temp = new node;
	temp = list[u];		

	while(temp != NULL){
		if (color[temp->vertex] == WHITE){
			parent[temp->vertex] = u;
			cout<<"vertex ->"<<temp->vertex<<endl;
			dfs_visit(temp->vertex);
		}
		temp = temp->next;
	}
	color[u] = BLACK;
	times = times + 1;
	dist[u] = times;
}

int dfs(int size){
	queue<int> q;
	int k;

	memset(color, WHITE, sizeof(color));
	memset(dist, INT_MAX, sizeof(dist));
	memset(parent, -1, sizeof(parent));

	times = 0;

	for (int i = 1; i<=size; i++){
		if(color[i] == WHITE){
			cout<<"call dfs-visit by "<<i<<endl;
			dfs_visit(i);
		}
	}
}


void input(int size) {
	int k, v, cost;
	cout<<"Enter the adjacency list\n";
	for (int i=1;i<=size;i++){
		cout<<"No of vertices it is connected to: ";
		cin>>k;
		cout<<"\nNow enter the vetices ";
		node *temp,*temp2;
		for (int j=1;j<=k;j++){
			cin>>v;
			cin>>cost;
			
			if (j==1){
				list[i] = new node;
				list[i]->vertex = v;
			//	list[i]->dist = cost;
				list[i]->next = NULL;
			}
			else if (j==2){
				temp = new node;
				temp->vertex = v;
			//	temp->dist = cost;
				temp->next = NULL;
				list[i]->next = temp;
			}
			else {  
				temp2 = new node;
				temp2->vertex = v;
			//	temp2->dist = cost;
				temp2->next = NULL;
				temp->next = temp2;
				temp = temp->next;
			}
		}
		temp = list[i];
		cout<<endl;
		while (temp!=NULL){
			cout<<temp->vertex<<"-> ";
			temp = temp->next;
		}
		cout<<endl;
		
	}
}


int main() {
	int s,n,r,i,j,nr, size, v1, v2;
	string s1,s2;
	cin>>size;
	input(size);

	dfs(size);

	for(i=1; i<=size; i++)
		cout<<i<<" "<<dist[i]<<endl;
}
