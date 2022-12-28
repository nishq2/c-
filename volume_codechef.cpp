//Chef is watching TV. The current volume of the TV is XX. Pressing the volume up button of the TV remote 
//increases the volume by 11 while pressing the volume down button decreases the volume by 11. Chef wants
//to change the volume from XX to YY. Find the minimum number of button presses required to do so.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int up,down,a,b,c;
	cout<<"enter the initial volume";
	cin>>a;
	cout<<"enter the final volume";
	cin>>b;
	c=abs(b-a);
	cout<<c<<"the min no of button press is:";
	return 0;
}

