#include<iostream>
using namespace std;

void maxheapify(int a[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=(2*i)+1;
    while(left<=n && a[left]>a[largest])
    {
        largest=left;
    }
    while(right<=n && a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        maxheapify(a,n,largest);
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void heapSort(int a[], int n)
{
    int i;
    for(i=0;i<n/2;i++)
    {
        maxheapify(a,n,i);
    }
    for(i=n;i>=1;i--)
    {
        swap(a[1],a[i]);
        maxheapify(a,n,1);
    }
}

int main()
{
    int i,j,arr[20];
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    //int lb=0;
    //int ub=n-1;
    cout<<"Enter elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Originial array"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr,n);
}