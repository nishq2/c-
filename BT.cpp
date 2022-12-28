#include<iostream>
#define MAX 50
using namespace std;
class node
{
    public:
    node *next;
    node *prev;
    node *lcl;
    node *rcl;
    int info;
    node()
    {
        next=NULL;
        prev=NULL;
        lcl=NULL;
        rcl=NULL;
    }
};

class stack
{
    public:
    int top;
    node *s[MAX];
    stack()
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
            cout<<"Stack underflow"<<endl;
            return NULL;
        }
        else
        return s[top--];

    }

    bool empty()
    {
        return top==-1;
    }

    node* topp()
    {
        return s[top];
    }
};

class BT
{
    public:
    node *root;
    BT()
    {
        root=NULL;
    }
    //DLL to binary tree

    void create()
    {
        cout<<"Enter root value"<<endl;
        root=createBT();
    }

    node* createBT()
    {
        int x;
        cin>>x;
        if(x==-1)
        return NULL;
        node *temp=new node;
        temp->info=x;
        cout<<"Left child of "<<x<<endl;
        temp->lcl=createBT();
        cout<<"Right child of "<<x<<endl;
        temp->rcl=createBT();
    }

   void inorder()
    {
        stack s1;
        //LNR
        if(root==NULL)
        return;
        node *temp=root;
        while(true)
        {
            if(temp!=NULL)
            {
                s1.push(temp);
                temp=temp->lcl;
            }
            else
            {
                if(s1.empty())
                break;
                temp=s1.topp();
                s1.pop();
                cout<<temp->info<<" ";
                temp=temp->rcl;
            }
        }
    }
};

int main()
{
    BT b1;
    b1.create();
    b1.inorder(b1.root);
    return 0;
}