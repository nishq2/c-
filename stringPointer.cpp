// Write a user defined function to count the number of vowels and consonants in a string
// using a pointer.
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char a[20];
    char *p;
    int vc=0, cc=0;
    cout<<"Enter a string"<<endl;
    cin>>a;
    p=&a[0];
    while(*p!='\0')
    {
        if(*p=='a'|| *p=='e'|| *p=='i' || *p=='o'|| *p=='u'|| *p=='A'|| *p=='E'|| *p=='I'|| *p=='O'|| *p=='U')
        {
            vc++;
        }
        else
        cc++;
    p++;
    }
    cout<<"The total vowels are: "<<vc<<" consontants: "<<cc<<endl;
    return 0;
}