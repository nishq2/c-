//prefix
#include<iostream>
#include<string.h>
#define MAX 50
using namespace std;

class stk
{
    char a[MAX];
    int top;
    public:
    stk()
    {
        top=-1;
    }

    void push(char c)
    {
        if(top==MAX-1)
        {
            cout<<"Stack overflow";
            return;
        }
        else
        a[++top]=c;
    }

    char pop()
    {
        if(top==-1)
        {
            return '$';
        }
        else
        return a[top--];
    }

    void convert()
    {
        char infix[MAX], pfix[MAX];
        cout<<"Enter the expression"<<endl;
        cin>>infix;
        strrev(infix);
        int i,k=0;
        
        for(i=0;i<strlen(infix);i++)
        {
            switch(infix[i])
            {
                case ')':
                push(infix[i]);
                break;

                case '(':
                while(((infix[i])=pop())!='(')
                {
                    pfix[k++]=infix[i];
                }
                break;

                case '*':
                case '/':
                case '+':
                case '-':
                if(precedence(infix[i])>=a[top])
                {
                    push(infix[i]);
                }

                else
                {
                    while(precedence(infix[i])<a[top])
                    {
                        pfix[k]=infix[i];
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
        strrev(pfix);
        cout<<pfix;
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
            break;
        }
    }
};

int main()
{
    stk s1;
    s1.convert();
    return 0;
}