#include<iostream>
#include<string.h>
using namespace std;
int main()
{

    char a[100];
    int i,len,temp;
    cout<<"string:\n";
    cin>>a;

    // for(i=0; a[i]!='\0';i++);
    // cout<<"length:\n";
    // cout<<i<<endl;

    len= strlen(a);
    

    for(i=0;i<len/2;i++)
    {
        temp=a[i];
        a[i]=a[i-len-1];
        a[i-len-1]=temp;
    }
    cout<<"Reversed str"<<a<<endl;



    return 0;


}
