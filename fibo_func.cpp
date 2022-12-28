//fibonacci
#include<iostream>
using namespace std;
int main()
{
	int fibo(int);
	int n;
	cout<<"enter a no";
	cin>>n;
	cout<<"fibonacci is"<<fibo(n);
}
int fibo(int n)
{
	int fibo;
	int i;
	int t1=0;
	int t2=1;
	int nextTerm;
	for (i=1;i<=n;i++)
	{
		if (i==1)
		{
			cout<<t1<<" ";
		}
		if (i==2)
		{
			cout<<t2<<" ";
		}
		nextTerm=t1+t2;
		t1=t2;
		t2=nextTerm;
		cout<<nextTerm<<" , ";
	}
	return fibo;
}
