#include<iostream>
#include<climits>
#include<string>
#include<queue>
#include<cstdlib>
#include<cstring>
#define MAX 10001

using namespace std;

int path[MAX], dist[MAX];
string names[MAX];

int find_city(string city, int n){
	int i;
	for(i=1;i<=n;i++)
		if (names[i] == city)
			break;
	return i;
}

class node {
	public:
		int vertex;
		int dist;
		node *next;
	node(){
		vertex = dist = 0;
	}
};

void initialize_single_source (int s, int size) {
	int i;
	memset(path, -1, sizeof(int)*MAX);
	memset(dist, -1, sizeof(int)*MAX);
	for (i=1; i<=size; i++) {
		dist[i] = INT_MAX;
		path[i] = -1;
	}
	dist[s] = 0;	
}

void relax (int u, int v, int uv){
	//cout<<"u="<<u<<" dist[u]="<<dist[u]<<" v= "<<v<<" dist[v]="<<dist[v]<<" uv="<<uv<<endl;
	if (dist[u] + uv < dist[v]) {
		dist[v] = dist[u] + uv;
		path[v] = u;
	}
	//cout<<"path to "<<v<<" "<<dist[v]<<endl;
}

node *list[MAX];

void input(int size) {
	int k, v, cost;

	for (int i=1;i<=size;i++){
		cin>>names[i];
		cin>>k;
		node *temp,*temp2;
		for (int j=1;j<=k;j++){
			cin>>v;
			cin>>cost;
			
			if (j==1){
				list[i] = new node;
				list[i]->vertex = v;
				list[i]->dist = cost;
				list[i]->next = NULL;
			}
			else if (j==2){
				temp = new node;
				temp->vertex = v;
				temp->dist = cost;
				temp->next = NULL;
				list[i]->next = temp;
			}
			else {  
				temp2 = new node;
				temp2->vertex = v;
				temp2->dist = cost;
				temp2->next = NULL;
				temp->next = temp2;
				temp = temp->next;
			}
		}
		/*temp = list[i];
		cout<<endl;
		while (temp!=NULL){
			cout<<temp->vertex<<"-> ";
			temp = temp->next;
		}
		cout<<endl;*/
		
	}
}

void min_dist(int s1, int s2, int n) {
	queue<int> q;
	int i, k, size;
	initialize_single_source(s1, n);
	node *temp = new node;
	temp = list[s1];
	q.push(s1);
	while(temp != NULL){
		q.push(temp->vertex);
		temp = temp->next;
	}

	while (!q.empty() ){
		k = q.front();
		q.pop();
//		cout<<"k= "<<k<<endl;
		temp = new node;
		temp = list[k];
		while(temp != NULL){
			relax(k, temp->vertex, temp->dist);
			temp = temp->next;	
		}
	}
	cout<<dist[s2]<<endl;
}

int main() {
	int s,n,r,i,j,nr,_s1,_s2, size;
	string s1,s2;
	cin>>s;
	while (s--){
		cin>>size;
		input(size);
	
		cin>>n;
		for (i=0;i<n;i++){
			cin>>s1>>s2;
			_s1 = find_city(s1, size);
			_s2 = find_city(s2, size);
			
			min_dist(_s1,_s2, size);
		}

	}
}
