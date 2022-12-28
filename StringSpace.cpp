#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    char a[50];
    char words[10][10];
    int i=0, wordIndex=0, totalWord=0;
    cout<<"Enter a string"<<endl;
    gets(a);
    for(i=0;i<=strlen(a);i++)
    {
        if(a[i]==' '|| a[i]=='\0')
        {
            words[totalWord][wordIndex]='\0';

            totalWord++;
            wordIndex=0;
        }
        else
        {
            words[totalWord][wordIndex]=a[i];

            wordIndex++;
        }
    }
    cout<<"Words from the string are:"<<endl;
    for(i=0;i<totalWord;i++)
    {
        cout<<words[i]<<endl;
    }
    return 0;
}