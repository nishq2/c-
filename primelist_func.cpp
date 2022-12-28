//prime list
#include<iostream>
using namespace std;
int main()
{
	int primeCheck(int);
	int n,m;
	cout<<"enter two no";
	cin>>n>>m;
	cout<<"prime between"<<n<<"&"<<m<<"are: "<<primeCheck(n);
	return 0;
}
void primeCheck(int n, int m)
{
	int flag=0,i;
	while(n<m)
	{
		for (i=2;i<n/2;i++)
		{
			if(n%i==0)
			{
				flag=1;
				break;
			}
		}
		if (flag==0)
		{
			cout<<n<<" ";
			n++;
		}
	}
}
