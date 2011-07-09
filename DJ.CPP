//dijktra's algorithm

#include<iostream>
#include<cstdio>
#define infi 999
using namespace std;

class queue
{
	private:
	int q[100];
	int front, rear;
	protected:
	queue()
	{
		front=rear=-1;
	}
	int isempty()
	{
		if((front==-1 && rear==-1) || (front>rear))
		{
			front=rear=-1;
			return 1;
		}
		return 0;
	}
	void push(int a)
	{
		if(isempty())
		front++;
		q[++rear]=a;
	};
	int del()
	{
		return q[front++];
	}
};
class dj :public queue
{
	private:
	int mat[10][10], dist[10], path[10];
	public:
	int n;
	void input()
	{
		cout<<"Enter number of nodes:\n";
		cin>>n;
		cout<<"\n\nEnter adjacency matrix\n"<<endl;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		cin>>mat[i][j];
	}
	void init(int m)
	{
		push(m);
		dist[m]=0;
		for(int i=1;i<=n;i++)
		{
			if(i!=m)
			{
				push(i);
				dist[i]=infi;
			}
			path[i]=0;
		}
	}
	void min_dist(int m)
	{
		int v, w;
		init(m);
		while(!(isempty()))
		{
			v=del();
			for(int i=1;i<=n;i++)
			{
				if(mat[v][i]!=0)
				{
					w=i;
					if((dist[v]+mat[v][w])<(dist[w]))
					{
						dist[w]=dist[v]+mat[v][w];
						path[w]=v;
					}
				}
			}
		}
	}
	void disp_path(int m)
	{
		int p=path[m];
		if(p==0)
		return;
		disp_path(p);
		cout<<" "<<m;
	}
	void disp_dist(int m)
	{
		cout<<"Cost: "<<dist[m]<<endl<<endl;
	}
};
int main()
{
	int c=0;
	dj a;
	a.input();
	cout<<"\n\nPress any key to continue"<<endl;

	for(int i=1;i<=a.n;i++)
	{
		a.min_dist(i);
		for(int j=1;j<=a.n;j++)
		{
			if(i!=j)
			{
				if(++c==10)
				{
					cout<<"\n\nPress any key to continue"<<endl;
					c=0;
				}
				cout<<"From "<<i<<" to "<<j<<":"<<endl;
				cout<<"------------"<<endl;
				cout<<"Minimum distance route: ("<<i;
				a.disp_path(j);
				cout<<")"<<endl;
				a.disp_dist(j);
			}
		}
	}
	cout<<"\n\nPress any key to exit"<<endl;
}

/*Output:

Enter number of nodes:
4


Enter adjacency matrix

0 1 5 4
1 0 2 6
5 2 0 3
4 6 3 0


From 1 to 2:
------------
Minimum distance route: (1 2)
Cost: 1

From 1 to 3:
------------
Minimum distance route: (1 2 3)
Cost: 3

From 1 to 4:
------------
Minimum distance route: (1 4)
Cost: 4

From 2 to 1:
------------
Minimum distance route: (2 1)
Cost: 1

From 2 to 3:
------------
Minimum distance route: (2 3)
Cost: 2

From 2 to 4:
------------
Minimum distance route: (2 1 4)
Cost: 5

From 3 to 1:
------------
Minimum distance route: (3 2 1)
Cost: 3

From 3 to 2:
------------
Minimum distance route: (3 2)
Cost: 2

From 3 to 4:
------------
Minimum distance route: (3 4)
Cost: 3

From 4 to 1:
------------
Minimum distance route: (4 1)
Cost: 4

From 4 to 2:
------------
Minimum distance route: (4 1 2)
Cost: 5

From 4 to 3:
------------
Minimum distance route: (4 3)
Cost: 3
*/











