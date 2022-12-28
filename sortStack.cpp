//bubble sort using stack
#include<iostream>
#define MAX 10
using namespace std;
class bubble
{
    int top;
    int a[MAX];
    public:
    bubble()
    {
        top=-1;
    }
    void push(int x);
    int pop();
    void sort();

};

void bubble::push(int x)
{
    if(top==MAX-1)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    a[++top]=x;
}

int bubble::pop()
{
    if(top==-1)
    {
        return -1;
    }

    return a[top--];
}

void bubble::sort()
{
    int i,n,x,a1[MAX];
    bubble s1;

    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>x;
    }
    for(i=0;i<n;i++)
    {
        push(a1[i]);
    }
for(i=0;i<n;i++)
{
    for(int j=i+1;j<n-1-i;j++)
    {
        if(a1[j]<a1[i])
        a1[j]=pop();

    }

    
}

    for(i=0;i<n;i++)
    {
        cout<<"the sorted array is: "<<a1<<endl;
    }
}


int main()
{
    bubble s1;
    s1.sort();
    return 0;
}

