// Write a function Reverse to reverse the elements of an integer array using pointer.
// Access the elements of the array using dereference operator.
// Read the values from the keyboard in main function. Display the result in the main function.

#include<iostream>
using namespace std;
int main()
{
    int a[10],i,n;
    int* p;
    cout<<"Enter the size of the array"<<endl;
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
    for(i=n-1;i>=0;i--)
    {
        cout<<" "<<*(p+i);
    }
    return 0;
}

// void Reverse(int n,int *p)
// {
//     int i;
//     cout<<"Reversed array is: "<<endl;
//     p=&a[n-1];
//     for(i=0;i<n;i++)
//     {
//         cout<<" "<<*(p+i)<<endl;
//         p--;
//     }
// }