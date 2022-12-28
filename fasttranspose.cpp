#include<iostream>
#define MAX 10
using namespace std;
class fspm
{
    int r,c,v;
    public:
    void read(fspm a[]);
    void transpose(fspm a[], fspm b[]);
    void display (fspm a[], fspm b[]);
};

void fspm:: read(fspm a[])
{
    int m,n,i,j;
    int k=1,x;
    cout<<"enter dimensions for the matrix:"<<endl;
    cin>>m>>n;
    cout<<"enter the elements"<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>x;
            if(x==0)
            {
                continue;
            }
            a[k].r=i;
            a[k].c=j;
            a[k].v=x;
            k++;
        }
    }
    a[0].r=m;
    a[0].c=n;
    a[0].v=k-1;
}

void fspm::transpose(fspm a[], fspm b[])
{
    int i,j,k=1;
    int rt[MAX], sp[MAX];
    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=a[0].v;
    for(i=0;i<a[0].c;i++)
    {
        rt[i]=0; //initialising to 0 so that we can increment later
    }

    for(i=1;i<a[0].c;i++)
    {
        rt[a[i].c]++;  //storing the column values
    }

    sp[0]=1;

    for(i=1;i<=a[0].c;i++)  //incrementing and checking for each col value
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

void fspm:: display(fspm a[], fspm b[])
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

int main()
{
    int x, ch;
    fspm a[MAX], b[MAX];
    fspm f1;
    
            f1.read(a);
            
           f1.transpose(a,b);
            
            f1.display(a,b);
            
    return 0;
}