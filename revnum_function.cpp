//reverse a number
#include <iostream>
using namespace std;
int main()
{
	int revnum(int);
	int n;
	cout<<"enter a number";
	cin>>n;
	cout<<"reversed number is"<<revnum(n);
	
}
int revnum(int n)
{
	int rev=0;
	int rem;
	while(n!=0)
	{
		rem=n%10;
		rev=rev*10 + rem;
		n/=10;
	}
	return rev;
}
