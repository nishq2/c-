#include<iostream>
#include<stdio.h>
using namespace std;
class Emp
{
    char name[20];
    int id;
    int sal;
    public:
    void input(Emp e[], int n);
    void display(Emp e[], int n);
};

void Emp::input(Emp e[], int n)
{
    for(int i=0;i<n;i++)
    {

    
    cout<<"Enter name"<<endl;
    cin>>e[i].name;
    cout<<"Enter id"<<endl;
    cin>>e[i].id;
    cout<<"Enter sal"<<endl;
    cin>>e[i].sal;
    }
}

void Emp::display(Emp e[], int n)
{
    for(int i=0;i<n;i++)
    {

    
    cout<<" "<<e[i].name;
    cout<<" "<<e[i].id;
    cout<<" "<<e[i].sal;
    }
}

int main()
{
    Emp e[10], e1;
    int n;
    cout<<"enter the total employees"<<endl;
    cin>>n;
    e1.input(e,n);
    e1.display(e,n);
}