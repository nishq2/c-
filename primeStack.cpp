#include<iostream>
#define MAX 10
using namespace std;
class prime
{
    int top;
    int a[MAX];
    public:
    prime()
    {
        top=-1;
    }
    void push(int x);
    int pop();
    void isPrime();
};

void prime::push(int x)
{
    if(top==MAX-1)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    a[++top]=x;
}

int prime::pop()
{
    if(top==-1)
    {
        //cout<<"Stack underflow"<<endl;
        return -1;
    }

    return a[top--];
}

void prime::isPrime()
{
    int i,j,x;
    int a1[MAX];

    cout<<"Enter a number"<<endl;
    cin>>x;
    if(x==0||x==1)
    {
        cout<<"not a prime"<<endl;
    }
    for(i=2;i<x;i++)
    {
       if(x%i==0)
       {
            push(a1[i]);
            cout<<"not a prime"<<endl;
       }
       else if(x%i!=0)
       {
        a1[i]=pop();
       cout<<"PRIME!"<<endl;
       } 

    }
}

int main()
{
    prime p1;
    p1.isPrime();
    return 0;
}