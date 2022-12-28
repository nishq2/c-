//program to read, display and to find the product of two matrices using functions with suitable parameters. 
#include<iostream>
using namespace std;
int main()
{
    int row,col,i,j;
    int a[10][10], b[10][10];
    int *p,*m,k,l;
    cout<<"Enter the dimensions of the matrices"<<endl;
    cin>>row>>col;
    cout<<"Enter the elements for matrix 1"<<endl;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
        cin>>*((p+i)+j);
        }
    }
    // cout<<"Enter the elements for matrix 2"<<endl;
    // for(k=0;k<row;k++)
    // {
    //     for(l=0;l<col;l++)
    //     {
    //         cin>>*((m+k)+l);
    //     }
    // }
    cout<<"Matrices are: "<<endl;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cout<<" "<<*((p+i)+j)<<endl;
        }
        cout<<"\n";
    }
    return 0;
}