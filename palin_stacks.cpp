//palindrome

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
    void palindrome();
};

void stk::push(char c)
{
    if (top==MAX-1)
    {
        cout<<"Stack overflow"<<endl;
    }

    else 
    str[++top]=c;
}

char stk::pop()
{
    if(top==-1)
    {
        cout<<"Stack underflow"<<endl;
        return '$';
    }

    return str[top--];

}

void stk::palindrome()
{
    char str1[10];
    cout<<"Enter a word"<<endl;
    cin>>str1;
    for(int i=0; str1[i]!='\0';i++)
    {
        push(str1[i]);
    }

    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]!=pop())
        {
            cout<<"Not a palindrome";
            return;
        }
    }
    cout<<"PALINDROME!";

}

int main()
{
    stk s1;
    s1.palindrome();
    return 0;
}