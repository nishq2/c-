//Write a program to convert a given decimal number to a number in any base using stack.
#include<iostream>
#define MAX 10
using namespace std;

class stk
{
    int top;
    int a[MAX];
    public:
    stk()
    {
        top=-1;
    }
    void push(int c);
    int pop();
    //void convert();
};

void stk::push(int c)
{
    if(top==MAX-1)
    {
        cout<<"Stack overflow";
        return;
    }
    else
    {
        a[++top]=c;
    }
}

int stk::pop()
{
    if(top==-1)
    {
        cout<<"stack underflow"<<endl;
        return -1;
    }
    else
    return a[top--];
}

int main()
{
    int n,b;
    int r, dig=0,p=1;
    stk s1;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<"Enter a base for conversion"<<endl;
    cin>>b;
    //int temp;
    //temp=n;
    while(n>0)
    {
        r=n%b;
        s1.push(r);
        n=n/b;
        
    }

    while(true)
    {
        r=s1.pop();
        if(r==-1)
        {
            break;
        }
        dig=dig*p+r;
        p=p*10;
    }

    cout<<dig<<endl;
    return 0;

}