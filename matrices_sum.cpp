#include <iostream>
using namespace std;
int main()
{
    int a[10][10], b[10][10], m,n,i,j,c[10][10];
    cout<<"enter no of rows\n";
    cin>>n;
    cout<<"enter no of column:\n";
    cin>>m;
    
    cout<<"enter elements of mat1:"<<endl;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"enter elements for mat2:"<<endl;
    for (i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>b[i][j];        
        }
    }
    for (i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            c[i][j]= a[i][j]+b[i][j];
        }

    }
    
    for (i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<"sum is:\n"<<c[i][j];
        }
    }
    //cout<<"sum is:\n"<<c[i][j];
    return 0;
}
