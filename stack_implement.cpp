//stack implementation
#include<iostream>
#define MAX 10
using namespace std;
class stk
{
    int top;
    int a[10];
    int x;
    public:
    stk()
    {
        top=-1;
    }
    void push(int x);
    int pop();
    void display();

};

void stk:: push(int x)
{
    
   
    if(top==MAX-1)
    {
        cout<<"Stack overflow"<<endl;

    }
    else
    {
        a[++top]=x;
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
        { 
            return a[top--];
        }
}


void stk::display()
{

    if(top==-1)
    {
        cout<<"stack is empty";
        return;
    }
    else
    {

    for(int i=top;i>=0;i--)
    
        cout<<a[i]<<endl;
    }    
}

int main()
{
    int ch;
    int x;
    stk s1;
    do
    {
        cout<<"Hello! please enter a choice corresponding to your wish\n 1.Insert\n 2.Delete\n 3.Display\n 4.To exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter an element:\n";
                cin>>x;
                s1.push(x);
                break;
            
            case 2:
                s1.pop();
                break;

            case 3:
                s1.display();
                break;

            default:
            cout<<"Invalid choice";
            break;
        }
    } while(ch!=4);
    return 0;
}