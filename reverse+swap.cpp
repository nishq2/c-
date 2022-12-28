#include<iostream>
//#include<string.h>
#include<stdio.h>

using namespace std;
int main()
{
    //swap last and first word and reverse middle 
    char a[20], b[20], c[20];
    int i,j,k,len;
    cout<<"Enter a string"<<endl;
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!=' ')
        {
            b[i]+=a[i];   
        }

        break;
    }
    for(i=0; a[i]!='\0';i++);
    cout<<"length:\n";
    cout<<i<<endl;
    len=(i+1);

    for(j=len-1;j>=i;j--)
    {
        if(a[j]!=' ')
        {
            c[j]+=a[j];
        }

        break;
    }
cout<<c;

for(k=i;k<=j;k++)
{
    cout<<a[k];
}
cout<<b;

return 0;
}
