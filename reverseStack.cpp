#include<iostream>
#define MAX 10
using namespace std;
class stk
{
    int top;
    char str[MAX];
    public:
    stk()
    {
        top=-1;

    }
    void push(char c);
    char pop();
    void reverse();
};

void stk::push(char c)
{
    if(top==MAX-1)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    str[++top]=c;
}

char stk::pop()
{
    if(top==-1)
    {
        return '$';
    }
     return str[top--];
}

void stk::reverse()
{
    char str1[MAX];
    int i;
    char a[MAX];
    cout<<"Enter a word"<<endl;
    cin>>str1;
    for(i=0;str1[i]!='\0';i++)
    {
        push(str1[i]);
    }
    for(i=0;str1[i]!='\0';i++)
    {
        str1[i]=pop();

    }
    cout<<"The reversed string is: "<<str1<<endl;

}

int main()
{
    stk s1;
    s1.reverse();
    return 0;
}