#include <iostream>
#include<string.h>
using namespace std;
#define MAX 20
class stk 
{
    public :
    int top;
    char a[MAX][40];

    stk()
    {
        top=-1;
    }

    bool isempty()
    {
        if (top==-1)
        return true;
        return false;
    }

    bool isfull()
    {
        if (top==MAX-1)
        return true;
        return false;
    }

    void push(char c[])
    {
        if (isfull())
        {
            cout<<"STACK FULL"<<endl;
            return ;
        }
        else 
        {
            int i;
            top++;
            for (i=0;i<strlen(c);i++)
            {
                a[top][i]=c[i];
            }
            a[top][i]='\0';
        }
    }

    void pop(char p[])
    {
        if (isempty())
        {
            cout<<"STACK EMPTY"<<endl;
            return ;
        }
        else 
        {
            int i;
            for (i=0;i<strlen(p);i++)
            {
                p[i]=a[top][i];
            }
            p[i]='\0';
            top--;
        }
    }

void fullyparenthesis(char ex1[], char op , char ex2[],char re[])
{
    int c1=strlen(ex1);
    //int c2=strlen(ex2);
   // int relen=strlen(ex1)+strlen(ex2)+3;
    int k=0;
    re[k++]='(';
    int h=0;
    while(k<=c1)
    re[k++]=ex1[h++];
    re[k]='\0';
    cout<<re<<endl;
    re[k++]=op;
    re[k]='\0';
    cout<<re<<endl;
    int g=0;
    while(ex2[g]!='\0')
    re[k++]=ex2[g++];
    re[k]='\0';
    cout<<re<<endl;
    re[k++]=')';
    //re[k++]=')';
    re[k]='\0';
    cout<<re<<endl;
}


void convert_to_fulexp(char t[]){
    stk s;
    int n=strlen(t);
    for (int i=0;i<n;i++)
    {
        char z=t[i];
        if (z>=97 && z<=122) {
        char w[3];
        w[0]=z;
        w[1]='\0';
        cout<<w<<endl;
        s.push(w); }
        else if (z=='+' || z=='-' || z=='*' || z=='/')
        {
            char e1[30],e2[30];
            s.pop(e2);
            s.pop(e1);
            char fin[40];
            switch(z)
            {
                case '+':
                {
                    fullyparenthesis(e1,z,e2,fin);
                    s.push(fin);
                    break;
                }
                case '-':
                {
                    fullyparenthesis(e1,z,e2,fin);
                    s.push(fin);
                    break;
                }
                case '/':
                {
                    fullyparenthesis(e1,z,e2,fin);
                    s.push(fin);
                    break;
                }
                case '*':
                {
                    fullyparenthesis(e1,z,e2,fin);
                    s.push(fin);
                    break;
                }
            }
        }
    }
    char ans[50];
    s.pop(ans);
    cout<<ans<<endl;
}
};

int main()
{
    stk s;
    char arr[]="wcab*+-";
    cout<<"Postfix form : "<<endl;
    convert_to_fulexp(arr);
    return 0;
}

