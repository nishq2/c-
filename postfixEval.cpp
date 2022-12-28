//postfix eval
#include<iostream>
#include<string.h>
#define MAX 50
using namespace std;

class postfixEval
{
    int a[MAX];
    int top;
    public:
    postfixEval()
    {
        top=-1;
    }
    
    void push(int x)
    {
        if(top==MAX-1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        else
        a[++top]=x;
        return;
    }

    int pop()
    {
        if(top==-1)
        {
            cout<<"Stack underflow"<<endl;
            return 0;
        }
        else
        return a[top--];
    }

    void eval()
    {
        char pfix[MAX];
        char b,c;
        int i,val;
        cout<<"Enter the expression"<<endl;
        cin>>pfix;
        //strrev(pfix);
        for(i=0;pfix[i]!='\0';i++)
        {
            if(pfix[i]=='+'||pfix[i]=='-'||pfix[i]=='*'||pfix[i]=='/'||pfix[i]=='^')
            {
                b=pop();
                c=pop();
                switch (pfix[i])
                {
                    case '*':
                    val=b*c;
                    break;

                    case '/':
                    val=b/c;
                    break;

                    case '+':
                    val=b+c;
                    break;

                    case '-':
                    val=b-c;
                    break;
                }
                
                push(val);
            }
            else
            push(pfix[i]-'0');
        }

        cout<<"Value is: "<<a[top]<<endl;
}
};


int main()
{
    postfixEval p1;
    p1.eval();
    return 0;
}