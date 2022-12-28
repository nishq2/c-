//insert a substring
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string str1("hello useless");
	string str2("manush");
	cout<< "original string\n" <<str1;
	str1.insert(6, str2);
	cout<<"\nusing insert: \n";
	cout<<str1;
	return 0;
}
