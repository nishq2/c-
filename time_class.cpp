//Define a class time with data members hour, min, sec .Write the user defined 
//functions to (i) Add (ii) To find difference between two objects of class time. 
//Functions take two time objects as argument and return time object. Also write the display and read function.

#include<iostream>
#include<stdio.h>
using namespace std;


class Time
{
    int hour;
    int mins;
    int sec;
    public: 
    void Print(void);
    void Add(Time T1, Time T2);
    void Diff(Time T1, Time T2);
    void Insert(void)
    {
        cout<<"enter time in sec\n";
        cin>>sec;
        hour=sec/3600;
        cout<<"\nhours:\n"<<hour;
        mins=sec/60;
        cout<<"\nmins:\n"<<mins;
        cout<<"\nsecs:\n"<<sec;

    }

};
void Time::Add(Time T1, Time T2)
{
    sec= T1.sec+T2.sec;
    mins= T1.mins + T2.mins;
    hour= T1.hour+T2.hour;
    //cout<<"time is"<<hour<<"hours"<<mins<<"mins"<<sec<<"sec"<<endl;
    cout<<endl;

}
void Time::Diff(Time T1, Time T2)
{
    if (T1.sec>T2.sec)
    {
        sec= T1.sec - T2.sec;
    }
     else if (T1.mins>T2.mins)
	    {
		mins= T1.mins- T2.mins;
    }
    else if ( T1.hour>T2.hour)
		{
		hour= T1.hour- T2.hour;
	}
    
    else if (T2.sec>T1.sec) 
    {
        sec= T2.sec - T1.sec;
        }
	else if (T2.mins>T1.mins)
	{
		mins= T2.mins- T1.mins;
	}
	else if(T2.hour>T1.hour)
        {
		hour= T2.hour- T1.hour;}
    
    //cout<< cout<<"time is"<<hour<<"hours"<<mins<<"mins"<<sec<<"sec"<<endl;

}
void Time::Print(void)
{
    cout<<"time after adding:\n";
    cout<<hour<<":"<<mins<<":"<<sec<<endl;
    cout<<"\ntime after diff:\n";
    cout<<hour<<":"<<mins<<":"<<sec<<endl;
}     
int main()
{
    Time T1, T2,T3, T4;
    T1.Insert();
    T2.Insert();
    T3.Add(T1,T2);
    T3.Print();
    T4.Diff(T1,T2);
    T4.Print();
    return 0;   
}