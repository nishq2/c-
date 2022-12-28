//Ezio can manipulate at most XX number of guards with the apple of eden.
//Given that there are Y number of guards, predict if he can safely manipulate all of them.

#include <iostream>
using namespace std;
int main() {
	int x,y;
	cout<<"Enter the number of apple of eden";
	cin>>x;
	cout<<"enter no of guards";
	cin>>y;
	if (x==y)
	{
		cout<<"safely manipulate";
	}
	else if (x>y)
	{
		cout<<"safely manipulate";
	}
	else 
	{
		cout<<"no manipulation";
	}
}
