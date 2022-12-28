#include<iostream>
#define MAX 100
using namespace std;
class stk
{
    int top;
    char a[MAX];

    public:
    stk()
    {
        top=-1;
    }
    void push(char c);
    char pop();
    void compute();
    void display();
};

void stk::push(char c)
{
    if(top==MAX-1)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    else
    a[++top]=c;
}

char stk::pop()
{
    if(top==-1)
    {
        cout<<"Stack underflow"<<endl;
        return '$';
    }

    else
    return a[top--];
}

void stk::compute()
{
    char a1[MAX], ele;
    int n,i;
    cout<<"Enter the total number of elements"<<endl;
    cin>>n;
    cout<<"Enter the char for MDBK"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>ele;
    }
    //char c;

    for(i=0;i<n;i++)
    {
        if(ele=='M')
        
           push(a1[i]);
        else 
        pop();

        if(ele=='D')
        push(a1[i]);
        else pop();

        if(ele=='B')
        push(a1[i]);
        else 
        pop();

        if(ele=='K')
        push(a1[i]);
        else 
        pop();

        
}
display();
}

void stk::display()
{
    int i;
    for(int i=0;i<=top;i++)
    {
        cout<<" "<<a[i];
    }
}

int main()
{
    stk s1;
    s1.compute();
    return 0;
}