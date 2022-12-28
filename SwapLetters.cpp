#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    //Swap last and first letter
    char a[20];
    int i;
    cout<<"enter a word"<<endl;
    cin>>a;
    int len=strlen(a);
    int temp=a[0];
    a[0]=a[len-1];
    a[len-1]=temp;
    cout<<a<<endl;
    return 0;
}