#include <iostream>
#define MAX 10
using namespace std;

class que
{
    int q[MAX], r,f;

    public:
    que()
    {
        r=-1;
        f=-1;
    }

    void enq(int x);
    int deq();
    void peek();
    void display();

};

void que::enq(int x)
{
    if(r==MAX-1)
    {
        cout<<"Queue is full"<<endl;
        return;
    }

    else
        q[++r]=x;
        return;
}

int que::deq()
{
    if(r==f)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else
    {
        cout<<"The deleted element is: "<<q[++f]<<endl;
        return q[f++];
    }
}

void que::peek()
{
    if(r==-1 && f==-1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    else
    cout<<" "<<q[f+1]<<endl;
}

void que::display()
{
    if(r==-1 && f==-1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    else
    {
        for(int i=0;i<=r;i++)
        {
            cout<<" "<<q[i];
        }
    }
}

int main()
{
    int ch, x;
   
    que q1;

    cout<<"Hello! pls choose a number you wish to implement"<<endl;
    
    do
    {
        cout<<"\n 1.To insert\n 2.To delete\n 3.To peek\n 4.To display\n 5.To exit"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter an element"<<endl;
                cin>>x;
                q1.enq(x);
                break;

            case 2:
                q1.deq();
                break;

            case 3:
                q1.peek();
                break;

            case 4:
                q1.display();
                break;

            default:
                cout<<"Invalid choice"<<endl;
                break;

        }

        
    }while(ch!=5);
    return 0;
}