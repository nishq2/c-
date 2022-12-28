#include <iostream>
using namespace std;
int main()
{
    int n, *p,i,j,temp;
    int a[10];
  
    cout<<"Enter the size"<<endl;
    cin>>n;
    p=&a[0];
    cout<<"Enter the elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>*(p+i);
    }
    for(i=0;i<n;i++)
    {
        cout<<" "<<*(p+i);
    }
      for (i=0;i<n;i++) 
      { 
        for (j=i+1;j<n;j++) 
        { 
  
            if (*(p+j)< *(p+i)) 
            { 
                temp=*(p+i); 
                *(p+i)=*(p+j); 
                *(p+j)=temp; 
            } 
        } 
    } 
    cout<<"\nSorted array is: ";
    for(i=0;i<n;i++)
    {
        cout<<" "<<*(p+i);
    }
    return 0;
}