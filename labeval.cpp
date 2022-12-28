#include<iostream>
using namespace std;
int main()
{
    int n,m,sum=0,diff=0;
    int a[10],b[10];
    int k;
    cout<<"enter two numbers\n";
    cin>>n>>m;
    sum+=n+m;
    if(n>m)
    {
        diff=n-m;
    }
    else
    {
        diff=m-n;
    }
    cout<<"\nthe sum is:"<<sum<<"\nand diff is:"<<diff;
    int r,p=1; 
    int count=0;
    int dig,rev;
    while(sum>0)
    {
        r=sum%2;
        sum=sum/2;
        dig=dig+r*p;
        p=p*10;
    }
    while(diff>0)
    {
        k=diff%2;
        diff=diff/2;
        rev=rev+k*p;
        p=p*10;
    }
    cout<<"\nThe diff in binary bits:"<<rev<<"\nThe sum in binary bit:"<<dig;
    
    int i,j;
    for(i=0;i<=sum;i++)
    
        a[i]=sum;
    for(j=0;j<=diff;j++)
        b[j]=diff;
    if(a[i]==a[j])
    {
        count++;
    }
    cout<<"\nthe common bits are:\n"<<count;
    
}