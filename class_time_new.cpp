//class time with data members hour, min, sec .Write the user defined 
//functions to (i) Add (ii) To find difference between two objects of class time. 
#include<iostream>
#include<stdio.h>
using namespace std;
class Time{
    int hour,mins,sec;
    public:
    void Evaluate(Time t1, Time t2);
    //void Print(void);
    void Insert(void)
    {
        cout<<"enter hours:\n";
        cin>>hour;
        cout<<"enter mins:\n";
        cin>>mins;
        cout<<"enter secs\n";
        cin>>sec;
        cout<<hour<<":"<<mins<<":"<<sec;

        //cin>>sec;
        //hour=sec/3600;
        //cout<<"\nhours:\n";
        //mins=sec/60;
        //cout<<"\nminutes:\n";
        
        
        
    }
};
void Time:: Evaluate(Time t1, Time t2)
{
    int hour, mins, sec;
    int a= t1.hour*3600+t1.mins*60+t1.sec;
    int b=t2.hour*3600+t2.mins*60+t2.sec;
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    } 
    int x= (a-b);
    hour= (x/3600);
    mins= ((x-hour*3600)/60);
    sec= (x-(hour*3600+mins*60));
    cout<<"time diff is:\n"<<x<<endl;
    cout<<hour<<":"<<mins<<":"<<sec<<endl;
    int y= (a+b);
    hour= (y/3600);
    mins= ((y-hour*3600)/60);
    sec= (y-(hour*3600+mins*60));
    cout<<"\ntime after adding is:\n"<<y<<endl;
    cout<<hour<<":"<<mins<<":"<<sec<<endl;

}
//void Time:: Print
int main()
{
    Time t1, t2;
    t1.Insert();
    t2.Insert();
    t1.Evaluate(t1,t2);
    t2.Evaluate(t1,t2);
    return 0;
}