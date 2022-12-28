//Write a program to input an infix expression and convert into its equivalent post fix form and display. Operands can be single character.
#include<iostream>
#include<stdio.h>
#define MAX 100
using namespace std;
class postfix
{
    //int a[MAX];
    char a[MAX];
    int top;
public:
    postfix()
    {
        top=-1;
    }
    void push(char c);
    char pop();
    void conv();
    int precedence(char c);
};

void postfix::push(char c)
{
    if(top==MAX-1)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    else
        a[++top]=c;
}

char postfix::pop()
{
    if(top==-1)
    {
        cout<<"Stack underflow"<<endl;
        return '$';
    }
    else
        return a[top--];
}

void postfix::conv()
{
   char infix[MAX],pfix[MAX];
    int k=0,i;
    char symbol;
    cout<<"Enter the expression"<<endl;
    gets(infix);
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        //if((symbol>='a'&&symbol<='z')||(symbol>='A' && symbol<='Z')||(symbol>='1' && symbol<='9'))
            //pfix[k]=infix[i];
        switch(infix[i])
        {
            case '(':

                push(infix[i]);
                break;


            case ')':

                    while((symbol=pop())!='(')
                        pfix[k++]=symbol;
                        break;

            case '+':
            case '-':
            case '*':
            case '/':

                if(precedence(infix[i])>precedence(a[top]))
                    push(infix[i]);
                else
                {
                    while(precedence(infix[i])<=precedence(a[top]))
                        pfix[k]=pop();
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
        cout<<"The postfix expression is:"<<pfix<<endl;
}


int postfix::precedence(char c)
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

int main()
{
    postfix p1;
    p1.conv();
    return 0;
}
