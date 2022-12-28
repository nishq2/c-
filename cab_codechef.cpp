//Chef has to travel to another place. For this, he can avail any one of two cab services.
//The first cab service charges XX rupees.
//The second cab service charges YY rupees.
//Chef wants to spend the minimum amount of money. Which cab service should Chef take?

#include <iostream>
using namespace std;

int main() {
	int x,y;
	cout<<"The charges for first cab:";
	cin>>x;
	cout<<"The charges for second cab:";
	cin>>y;
	if (x<y)
	{
	    cout<<"FIRST";
	}
	else if (y<x)
	{
	    cout<<"SECOND";
	}
	else 
	cout<<"ANY";
	return 0;
}

