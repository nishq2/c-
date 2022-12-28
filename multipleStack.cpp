//multiple stacks
#include<iostream>
#define MAX 10
using namespace std;
class stk
{
int a[MAX];
public:
int topx, topy;
stk()
{
topx=-1;
topy=MAX;
}
void push_X(int ele);
int pop_X();
void display_X();
void push_Y(int val);
int pop_Y();
void display_Y();
};

void stk::push_X(int ele)
{

if(topx==topy-1)

{

cout<<"Stack overflow"<<endl;

return;

}

else

a[++topx]=ele;



}



int stk::pop_X()

{

if(topx==-1)

{

cout<<"stack underflow"<<endl;

return -1;

}



else

return a[topx--];

}



void stk:: display_X()

{

if(topx==-1)

{

cout<<"empty stack";

return;

}



else 
for(int i=0;i<=topx;i++)

{

cout<<" "<<a[i];

}

}



void stk::push_Y(int val)

{

if(topy==topx-1)

{

cout<<"Stack overflow"<<endl;

return;

}
else a[topy--]=val;

}



int stk::pop_Y()

{

if(topy==MAX)

{

cout<<"Stack underflow";

return -1;

}

else

return a[++topy];

}



void stk::display_Y()

{

if(topy==MAX)

{

cout<<"stack is empty"<<endl;

}



else

{

for(int i=MAX-1;i<=topy;i--)

cout<<" "<<a[i];

}

}


int main()
{
int ele, val;
stk s1;
int ch;
do

{

cout<<"Hello! pls choose a no you wish to implement"<<endl;

cout<<"1.Insert X\n 2.Insert Y\n 3.Delete X\n 4.Delete Y\n 5.Display X\n 6.Display Y\n 7.To
 exit\n";

cin>>ch;

switch(ch)
{

case 1:

cout<<"Enter an element"<<endl;

cin>>ele;

s1.push_X(ele);

break;



case 2:

cout<<"Enter an element"<<endl;

cin>>val;

s1.push_Y(val);

break;



case 3:

s1.pop_X();

break;



case 4:

s1.pop_Y();

break;



case 5:

s1.display_X();

break;



case 6:

s1.display_Y();

break;



default:

cout<<"Invalid choice";

break;

}

}while(ch!=7);



return 0;

}