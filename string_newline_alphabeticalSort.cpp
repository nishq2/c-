//display each word of a string individually and sort alphabeticslly
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char s[100];
    int i,j,temp,n;
    int count=0;
    cout<<"enter s string:\n";
    gets(s);
    //cout<<s<<endl;
     
    //if words to be displayed individually then we'll read each word and wherever we encouter a space 
    //there add a new line
    //if(s[i]==' ' || s[i]=='\0')
    for(i=0; s[i]!='\0';i++)
    {
        if(s[i]==' ')
    {
       cout<<"\n"; 
    }
        //cout<<"\n";
        //i++;
    } 
    for(i=0; s[i]!='\0';i++);
    cout<<"length:\n";
    cout<<i<<endl;

   
    for(i=0;i<s[i];i++)
    {
        for (j=i+1;j<s[j];j++)
        {
            if (s[j]<s[i])
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
        
    }
    cout<<"the alphabetically sorted string order:\n";
    cout<<s<<endl;
    return 0;

}