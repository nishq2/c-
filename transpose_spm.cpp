//transpose
#include<iostream>
#define MAX 10
using namespace std;
class tspm
{
    int r,c,v;
    public:
    void read(tspm a[]);
    void transpose(tspm a[], tspm b[]);
    void display(tspm a[], tspm b[]);

};

void tspm::read(tspm a[])
{
    int i,j,m,n,ele;
    int k=1;
    cout<<"Enter the dimensions"<<endl;
    cin>>m>>n;
    cout<<"Enter the elements"<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>ele;
            if(ele==0)
            {
                continue;
            }
            a[k].r=i;
            a[k].c=j;
            a[k].v=ele;
            k++;
        }
    }
    a[0].r=m;
    a[0].c=n;
    a[0].v=k-1;
}

void tspm::transpose(tspm a[], tspm b[])
{
    int k=1,i,j;
    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=a[0].v;

    for(i=0;i<a[0].c;i++)
    {
        for(j=1;j<a[0].v;j++)
        {
            if(i==a[j].c)
            {
            b[k].r=a[j].c;
            b[k].c=a[j].r;
            b[k].v=a[j].v;
            k++;
            }
        }
    }
}

void tspm::display(tspm a[], tspm b[])
{
     cout<<"Matrix:"<<endl;
    for(int i=0;i<a[0].v;i++)
    {
       
        cout<<a[i].r<<" "<<a[i].c<<" "<<a[i].v<<endl;
    }
     cout<<"After transpose:"<<endl;
    for(int j=0;j<b[0].v;j++)
    {
       
        cout<<b[j].r<<" "<<b[j].c<<" "<<b[j].v<<endl;

    }
}

int main()
{
    tspm  a[MAX], b[MAX];
    tspm t1;
    t1.read(a);
    t1.transpose(a,b);
    t1.display(a,b);
}