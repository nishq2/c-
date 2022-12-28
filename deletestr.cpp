//delete substring
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string str("hello world");
	cout<<"bfr delete: \n";
	cout<<str;
	//string str2("worl");
	str.erase(1,4); 
	cout<<"\nafter delete:\n";
	cout<<str;
	return 0;
	
}
