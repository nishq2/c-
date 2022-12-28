#include<iostream>
#include<queue>
//#define MAX 50
using namespace std;
// class queue
// {
//     int r;
//     int f;
//     int a[MAX];
//     public:
//     queue()
//     {
//         r=f=-1;
//     }
//     bool empty()
//     {
//         if(r==-1||r==f)
//         {
//             return true;
//         }
//         else
//         return false;
//     }
//     void push(int x)
//     {
//         if(r==MAX-1)
//         {
//             cout<<"Queue is full"<<endl;
//             return;
//         }
//         else
//         a[++r]=x;
//     }
//     void front()
//     {

//     }
// };
class stk
{
    queue<int> q1, q2;
    public:
    void push(int x)
    {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue q=q1;
        q1=q2;
        q2=q;
    }

    void pop()
    {
        if(q1.empty())
        return;
        q1.pop();
    }
    int peek()
    {
        if(q1.empty())
        return 0;
        else
        return q1.front();
    }
};



int main()
{
    stk s;
    s.push(10);
    s.pop();
    s.push(20);
    int x=s.peek();
    return 0;
}