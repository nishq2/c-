#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    char str[50];
    int p,i,n,len;
    cout<<"enter a string\n";
    gets (str);
   //for(len=0;str[len]!='\0';len++)
    cout<<"enter pos of substr to be deleted\n";
    cin>>n;
    for(len=0;str[len]!='\0';len++)
    if (n>len)
    {
        cout<<"starting postn must be less than str size\n";
    }
    else {
        cout<<"enter the no of chars to be deleted";
        cin>>p;
        if (n+p>=len){

        
        p=  len-n+1;
        for (i=n-1; str[i]!='\0';i++)
        str[i]=str[i+p];
         } cout<<"\nthe str is:\n"<<str;
    }
    return 0;
    }

