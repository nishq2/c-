//strcmp
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char str1[50],str2[50];
	int a;
	cout<<"enter str1";
	gets(str1);
	cout<<"enter str2";
	cin>>str2;
	gets(str2);
	if (strcmp(str1,str2)>0) 
	{
		cout<<"str1>str2";
	}
	else if (strcmp(str1,str2)<0)
	{
		cout<<"str1<str2";
	}
	else if (strcmp(str1,str2)==0)
	{
		cout<<"str1=str2";
	}
	return 0;
}
