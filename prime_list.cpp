//prime list
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int i,j,m,n;
    int flag=0;
    cout<<"enter lower limit"<<endl;
    cin>>m;
    cout<<"enter upper limit"<<endl;
    cin>>n;
    for(i=m;i<=n;i++)
    {
        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if (flag==1 && i!=1)
        cout<<"i"<<endl;
    }
    return 0;
}
