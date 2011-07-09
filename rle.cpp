#include<iostream>
#include<string>
using namespace std;

int main(){
	string s = "aaahhhbbgggff";
	int len = s.length(), count;
	char key =  s[0];
	count = 0;

	for (int i=0; i<len; i++)
	{	if (key == s[i])
			count++;
		else {
			cout<<key<<count;
			key = s[i];
			count = 1;
		}
	}
	cout<<key<<count<<endl;
}
