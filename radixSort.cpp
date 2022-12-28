//radix sort
#include<iostream>
using namespace std;


int getMax(int arr[],int n)
{
    int max=arr[0];
    int temp;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            temp=max;
            max=arr[i];
            arr[i]=temp;
        }
    }
    //cout<<"MAX"<<max<<endl;
    return max;
}

void countSort(int a[], int n, int pos)
{
    int count[10]={0};
    int b[20];
    int i;
    for(i=0;i<n;i++)
    {
        ++count[(a[i]/pos)%10];
    }

    for(i=0;i<n;i++)
    {
        count[i]=count[i]+count[i-1];
    }

    
    for(i=n-1;i>=0;i--)
    {
        b[--count[(a[i]/pos)%10]]=a[i];
    }

    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }
    
    cout<<"Sorted"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void radixSort(int a[], int n)
{
    int max=getMax(a,n);
    int pos;
    for(pos=1;max/pos>0;pos*10)
    {
        countSort(a,n,pos);
    }
}


int main()
{
    int i,n,a[50];
    cout<<"Enter array size"<<endl;
    cin>>n;
    cout<<"Enter elemetns"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Unsorted"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    getMax(a,n);
    radixSort(a,n);
}

