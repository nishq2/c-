#include <iostream>
using namespace std;
int main()
//int factnum(int n, int i);
{
	int factnum (int);
	int n;
	
	cout<<"enter a number";
	cin>>n;
	cout<<"factorial is"<<factnum(n);
	
	
}
int factnum(int n)
{
	int fact=1;
	int i;
	for (i=n;i>=1;i--)
	{
		fact*=i;
	}
	return fact;
}
