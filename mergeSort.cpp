//merge sort
#include<iostream>
using namespace std;

void merge(int a[], int lb, int mid, int ub)
{
    int b[20];
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }

    if(i>mid)
    {
        while(j<=ub)
        {
        b[k]=a[j];
        j++;
        k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    
    for(k=lb;k<=ub;k++)
    {
        a[k]=b[k];
    }
    
    cout<<endl;

    for(k=lb;k<=ub;k++)
    {
        cout<<a[k]<<" ";
    }
}

void mergesort(int a[], int lb, int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
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
    mergesort(arr,lb,ub);
}