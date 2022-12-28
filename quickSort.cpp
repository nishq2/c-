#include<iostream>
using namespace std;

int partition(int a[], int lb, int ub)
{
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    int temp=0;
    while(start<end)
    {
        while(a[start]<=pivot)
        start++;

        while(a[start]>pivot)
        end--;

        if(start<end)
        {
            temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }

    if(start>end)
    {
        temp=a[end];
        a[end]=a[lb];
        a[lb]=temp;
    }
    return end;

}

void quicksort(int a[], int lb, int ub)
{
    if(lb<=ub)
    {
        int loc=partition(a, lb, ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    for(int i=lb;i<=ub;i++)
    {
        cout<<a[i]<<" ";
    }
    }
}

int main()
{
    int i,j,arr[20];
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    int lb=0;
    int ub=n-1;
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
    quicksort(arr,lb,ub);
}