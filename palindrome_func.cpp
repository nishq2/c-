//palindrome
#include<iostream>
using namespace std;
int main()
{
	int palindrome(int);
	int n;
	cout<<"enter a no";
	cin>>n;
	cout<<" "<<palindrome(n);
	
	
}
int palindrome(int n)
{
	int palindrome=0;
	int rem;
	while(n!=0)
	{
		n=n%10;
		palindrome=palindrome*10+rem;
		n/=10;
		
	}
	if (n==palindrome)
	{
		cout<<"palindrome";
	}
	else 
	{
		cout<<"not a palindrome";
	}
	return palindrome;
}
