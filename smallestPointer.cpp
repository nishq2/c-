//Write  a  function  Smallest  to  find  the  smallest  element  in  an  array  using  pointer. 

#include<iostream>
using namespace std;
int main()
{
    int n, *p,i,min;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    cout<<"Enter elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>*(p+i);
    }
    for(i=0;i<n;i++)
    {
        cout<<" "<<*(p+i)<<endl;
    }
    min=*p;
    for(i=0;i<n;i++)
    {
        if(*(p+i)<min)
        min=*(p+i);
    }
    cout<<"The smallest element is: "<<min<<endl;
    return 0;
}