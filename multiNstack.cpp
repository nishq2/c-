#include<iostream>
#define MAX 10
using namespace std;

class mstk
{
    int b[MAX],top[MAX],a[MAX];
    int i,n;
    public:
    mstk()
    {
        for(int i=0;i<n;i++)
        b[i]=top[i]=(MAX/n)*i-1;
    }
    void push(int x, int i);
    void pop(int i);
    void display(int i);
};

void mstk::push(int x, int i)
{
    if((top[i]==b[i+1]) || (top[i]==MAX-1))
    {
        cout<<"stack overflow"<<endl;
        return;
    }
    else
    a[++top[i]]=x;
}

void mstk::pop(int i)
{
    if(top[i]==b[i])
    {
        cout<<"stack underflow"<<endl;
        return;
    }
    else
    cout<<"deleted element is: "<<a[--top[i]]<<endl;
}

void mstk::display(int i)
{
    cout<<"Stack to be displayed"<<endl;
    cin>>i;
    for(i=top[i];i>=b[i];i--)
    {
        cout<<" "<<a[i];
    }
    //cout<<a[i]<<endl;
}

int main()
{
    int x,ch,i,n;
    mstk m1;
    cout<<"Enter the no of stacks"<<endl;
    cin>>n;
    cout<<"Enter a no you wish to implement"<<endl;
    do
    {
        cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter an element"<<endl;
            cin>>x;
            m1.push(x,i);
            break;

            case 2:
            m1.pop(i);
            break;

            case 3:
            m1.display(i);
            break;

            default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }while(ch!=0);
    return 0;
}