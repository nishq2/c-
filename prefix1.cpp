//prefix
#include<iostream>
#define MAX 50
#include<string.h>

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

    void convert()
    {
    char infix[MAX],pfix[MAX];
    int k=0,i;
    char symbol;
    cout<<"Enter the expression"<<endl;
    cin>>infix;
    strrev(infix);
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        //if((symbol>='a'&&symbol<='z')||(symbol>='A' && symbol<='Z')||(symbol>='1' && symbol<='9'))
            //pfix[k]=infix[i];
        switch(infix[i])
        {
            case ')':

                   push(infix[i]);
                break;


            case '(':

                    while((symbol=pop())!=')')
                        pfix[k++]=symbol;
                        break;

            case '+':
            case '-':
            case '*':
            case '/':

                if(precedence(infix[i])>=precedence(a[top]))
                    push(infix[i]);
                else
                {
                    while(precedence(infix[i])<precedence(a[top]))
                        pfix[k]=pop();
                }
                    break;


            default:
                pfix[k++]=infix[i];
                break;
                }


             }

         while(top!=-1)
             {
                pfix[k++]=pop();

             }
        pfix[k]='\0';
        strrev(pfix);
        
        cout<<"The prefix expression is: "<<pfix<<endl;
    }

    // void reversed(char z[])
    // {
    //     char b[MAX];
    //     int i,k=0;
    //     int len= strlen(z);
    //     for(z[i]!='\0';i>=0;i--)
    //     {
    //         if(z[i]==')')
    //         {
    //             b[k++]='(';
    //             continue;
    //         }
    //         else if(z[i]=='(')
    //         {
    //             b[k++]=')';
    //             continue;
    //         }
    //         else
    //         b[k++]=z[i];
    //     }  
    //         for(i=0;i<len;i++)
    //         { z[i]=b[i]; }
    //         z[i]='\0';
    //         cout<<z<<" "<<b<<endl;
    // }

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
};

int main()
{
    prefix p1;
    p1.convert();
    return 0;
}
