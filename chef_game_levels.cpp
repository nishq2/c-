//Chef is playing a videogame, and is getting close to the end. He decides to finish the rest of the game in a single session.
//There are X levels remaining in the game, and each level takes Chef Y minutes to complete. 
//To protect against eye strain, Chef also decides that every time he completes 3 levels, he will take a Z minute break from playing. 
//Note that there is no need to take this break if the game has been completed.
//How much time (in minutes) will it take Chef to complete the game?

#include <iostream>
using namespace std;
int main()
{
	int a,x,y,z,gaps,t;
	cout<<"No of levels remaining in the game";
	cin>>x;
	cout<<"no of minutes to complete each level";
	cin>>y;7
	cout<<"minute break=?";
	cin>>z;
	a=x%3;
	if (a==0)
	{
		gaps=a;
	}
	else if (a!=0)
	{
		gaps= a-1;
	}
	t= (x*y) + (gaps*z);
	cout<<t<<"time for chef to complete the game:";
}
