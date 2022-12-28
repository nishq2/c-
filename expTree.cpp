// Online C++ compiler to run C++ program online
#include <iostream>
#include<string.h>
#define MAX 50
using namespace std;

class node
{
    public:
    node *right;
    node *left;
    char info;
    node(char c)
    {
        info=c;
        right=left=NULL;
    }
};
class stk
{
    public:
    int top;
    node *s[MAX];
  
    stk()
    {
        top=-1;
    }

    void push(node *x)
    {
        if(top==MAX-1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        else
        s[++top]=x;
    }

    node* pop()
    {
        if(top==-1)
        {
            return NULL;
        }
        else
        return s[top--];
    }

    bool isEmpty()
    {
        return top==-1;
    }

    node* topp()
    {
        return s[top];
    }
};

bool isOp(char c)
{
    return c=='/' || c=='+' || c=='*' || c=='-';
}
node* create(char pfix[])
{
    int i,j;
    stk s1;
    for(i=0;pfix[i]!='\0';i++)
    {
    if(!isOp(pfix[i]))
    {
        node *temp=new node(pfix[i]);
        s1.push(temp);
    }
    else
    {
        node *temp=new node(pfix[i]);
        temp->right=s1.topp();
        s1.pop();
        temp->left=s1.topp();
        s1.pop();
        s1.push(temp);
    }
    }
    return s1.topp();
}

void infix(node *root)
{
    if(root==NULL)
    return;
    
    infix(root->left);
    cout<<root->info;
    infix(root->right);
}

int main()
{
    char pfix[MAX];
    cout<<"Enter postfix exp"<<endl;
    cin>>pfix;
    node *root=NULL;
    root=create(pfix);
    infix(root);
    
    return 0;
}

