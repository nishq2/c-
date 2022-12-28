//circular queue

#include<iostream>
#define MAX 10
using namespace std;
class que
{
    int r,f;
    int q[MAX];
    public:
    que()
    {
        r=-1;
        f=-1;
    }

    void enq(int x);
    void deq();
    void peek();
    void display();
};

void que::enq(int x)

{
    if((r+1)%MAX==f)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    else
    {
        r=(r+1)%MAX;
        q[r]=x;
        return;
    }
}

void que::deq()
{
    if(r==f)
    {
        cout<<"queue is empty"<<endl;
        return;
    }

    else
    {
        f=(f+1)%MAX;
        cout<<"The deleted element is: "<<q[f]<<endl;
        //return q[f++];
    }
}

void que::peek()
{
    if(r==f)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else
    {
        cout<<q[f+1]<<endl;
        return;
    }
}

void que::display()
{
   int i;
   if(r==f)
   {
    cout<<"Queue is empty"<<endl;
    return;
   }
        for(i=f+1; i!=r; i=(i+1)%MAX)
        {
            cout<<q[i]<<endl;
        } 
        cout<<q[i]<<endl;
    
}

int main()
{
    int x,ch,i;
    que q1;
    cout<<"Hello! pls choose a no you wish to implement"<<endl; 
    do
    {
        cout<<"1.To insert\n 2.To delete\n 3.To peek\n 4.To display\n 5.To exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter an element:"<<endl;
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
    }  while(ch!=5);

    return 0;
}