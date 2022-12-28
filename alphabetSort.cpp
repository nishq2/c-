#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char a[50];
    int i,j,k,len;
    int temp;
    cout<<"enter a string"<<endl;
    cin>>a;
    for(i=0; a[i]!='\0';i++);
    cout<<"length:\n";
    cout<<i<<endl;

    len=i+1;

    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }

        }
    }
    cout<<"Sorted string: "<<a[i]<<endl;
    return 0;
}