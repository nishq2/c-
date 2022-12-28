//prefix
#include<iostream>
#define MAX 50
using namespace std;

class prefix
{
    char a[MAX];
    int top;
    public:
    prefix()
    {
        top=-1;
    }

    void push(char c)
    {
        if(top==MAX-1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        else
        a[++top]=c;
        return;
    }

    char pop()
    {
        if(top==-1)
        {
            cout<<"stack underflow"<<endl;
            return '$';
        }
        else
        return a[top--];
    }

    void reverss()
    {
        char a[MAX],b[MAX];
        int i,k=0;
        for(i=strlen(a)-1;i>=0;i++)
        {
            if(a[i]==')')
            {
                b[k++]='(';
                continue;
            }
            else if(a[i]=='(')
            {
                b[k++]=')';
                continue;
            }
            else
            b[k++]=a[i];
            for(i=0;i<strlen(a);i++)
            a[i]=b[i];
            a[i]='\0';
        }
    }

    int precedence(char c)
    {
        switch(c)
        {
            case '^':
            return 4;
            break;

            case '*':
            case '/':
            return 3;
            break;

            case '+':
            case '-':
            return 2;
            break;

            case '(':
            case ')':
            return 1;
            break;

            default:
            return 0;
        }
    }

    void convert()
    {
        char infix[MAX], pfix[MAX];
        int i,k=0;
        cout<<"Enter the expression"<<endl;
        cin>>infix;
        for(i=0;infix[i]!='\0';i++)
        {
            switch(infix[i])
            {
                case '(':
                push(infix[i]);
                break;

                case ')':
                while(infix[i]=pop()!='(')
                {
                    pfix[k++]=pop();
                }
                break;

                case '*':
                case '/':
                case '+':
                case '-':
                if(precedence(infix[i])>=precedence(a[top]))
                {
                    push(infix[i]);
                }
                else
                {
                    if(precedence(infix[i])<predence(a[top]))
                    {
                        pfix[k]=pop();
                    }
                }
                break;

                default:
                pfix[k++]=infix[i];
            }
        }
        while(top!=-1)
        {
            pfix[k++]=pop();
        }
        pfix[k]='\0';
        reverss(pfix);
        cout<<"Prefix form is: "<<pfix<<endl;
    }
};

int main()
{
    prefix p1;
    p1.convert();
    return 0;
}
