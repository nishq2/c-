//prime
#include<iostream>
using namespace std;
int main()
{
	int prime(int);
	int n;
	cout<<"enter a no";
	cin>>n;
	cout<<" "<<prime(n);
}
int prime(int n)
{
	int prime;
	int flag=0;
	int i;
	for (i=2;i<n/2;i++)
	{
		if(n%i==0)
		{
			cout<<"not a prime";
			flag=1;
			break;
		}
		
	}
	if (flag==0)
	{
		cout<<"is prime";
	}
	return prime;
}
