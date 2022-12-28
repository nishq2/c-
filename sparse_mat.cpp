//sparse matrix
#include<iostream>
#define MAX 10
using namespace std;

class spm
{
    int r,c,v;
    public:
    void read(spm a[])
    {
        int k=1, m,n;
        int i,j,ele;
        cout<<"enter the dimensions for the matrix"<<endl;
        cin>>m>>n;
        cout<<"enter the elements"<<endl;
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

    void display(spm a[])
    {
        for(int i=0;i<a[0].v;i++)
        cout<<a[i].r<<" "<<a[i].c<<" "<<a[i].v<<endl;
    }
};

int main()
{
    spm a[MAX];
    spm a1;
    a1.read(a);
    a1.display(a);
    return 0;

}