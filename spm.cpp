#include <iostream>
#define MAX 50
using namespace std;

class spm
{
    int r,c,v;
    public:

    void read(spm a[])
    {
        spm b[MAX];
        int m,n,i,j;
        int k=1,ele;
        int count=0;
        cout<<"Enter dimensions"<<endl;
        cin>>m>>n;
        cout<<"Enter elements"<<endl;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>ele;
                if(ele==0)
                {
                    count++;
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

        if(count>(m*n)/2)
        {
            fasttranspose(a,b);
        }

        else
        {
            cout<<"Not a sparse matrix"<<endl;
        }
    }

    void fasttranspose(spm a[], spm b[])
    {
    int i,j,k=1;
    int rt[MAX], sp[MAX];
    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=a[0].v;
    for(i=0;i<a[0].c;i++)
    {
        rt[i]=0;
    }

    for(i=1;i<a[0].c;i++)
    {
        rt[a[i].c]++;  
    }

    sp[0]=1;

    for(i=1;i<=a[0].c;i++)  
    {
        sp[i]= sp[i-1] + rt[i-1];
    }

    for(i=1;i<=a[0].v;i++)
    {
        
        k= sp[a[i].c]++;
        b[k].r=a[i].c;
        b[k].c=a[i].r;
        b[k].v=a[i].v;
        
    }
    }

    void display(spm a[], spm b[])
{
    cout<<"Matrix:"<<endl;
    for(int i=0;i<=a[0].v;i++)
    {
        cout<<a[i].r<<" "<<a[i].c<<" "<<a[i].v<<endl;
    }
    cout<<"After transpose:"<<endl;
    for(int j=0;j<=b[0].v;j++)
    {
        cout<<b[j].r<<" "<<b[j].c<<" "<<b[j].v<<endl;
    }
}
};

int main()
{
    spm s1;
    spm a[MAX], b[MAX];
    s1.read(a);
    s1.display(a,b);
}