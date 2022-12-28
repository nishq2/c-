
#include<iostream>
#include<stdio.h>
using namespace std;
class Student
{
    int n,i;
    int marks[5];
    public:
    //int calculateTotalScore();
    void input(void)
    {
        cout<<"enter the marks for each subject:\n";
        for (int i=0;i<5;i++)
        {
            cin>>marks[i];
        }
    }
    int calculateTotalScore()
    {
        int count=0;
        for (i=0;i<5;i++)
        {
            count+= marks[i];
           //count++;
        }
        cout<<"\nThe total score is:\n"<<count<<endl;
    }
};
    int main()
    {
        int n, kristen_s,i;
        //Student s[], s1[100];
        cout<<"Enter total no of students:\n";
        cin>>n;
        Student *s1 = new Student[n];
        for (int i=0; i<n;i++)
        {
            s1[i].input();
        }
        kristen_s= s1[0].calculateTotalScore();
        int count=0;
        for (int i=1;i<n;i++)
        {
            int total= s1[i].calculateTotalScore();
             if (kristen_s<total)
            {
                count++;
            }
            //cout<<count<<endl;
            
        }
        cout<<count<<endl;
    return 0;
    }