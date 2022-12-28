#include<iostream>
#define MAX 50
using namespace std;
class node
{
    public:
    node *next;
    node *rcl;
    node *lcl;
    int info;
    node()
    {
        next=NULL;
        rcl=NULL;
        lcl=NULL;
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

class BT
{
    public:
    node *root;
    BT()
    {
        root=NULL;
    }

    void create()
    {
        stk s1;
        //1: input value
        node *t,*p;
        int x;
        root=new node;
        cout<<"Enter root value"<<endl;
        cin>>x;
        root->info=x;
        root->lcl=root->rcl=NULL;
        s1.push(root);
        while(!s1.isEmpty())
        {
            p=s1.pop();
            cout<<"Enter left of: "<<p->info<<endl;
            cin>>x;
            if(x!=-1)
            {
                t=new node;
                t->info=x;
                t->rcl=t->lcl=NULL;
                p->lcl=t;
                s1.push(t);
            }
            cout<<"Enter right of: "<<p->info<<endl;
            cin>>x;
            if(x!=-1)
            {
                t=new node;
                t->info=x;
                t->rcl=t->lcl=NULL;
                p->rcl=t;
                s1.push(t);
            }
        }
    }
  void inorder()
    {
        //LNR
        stk s1;
        node *temp;
        temp=root;
        if(!temp)
        {
            return;
        }
        while(true)
        {
            if(temp!=NULL)
            {
                s1.push(temp);
                temp=temp->lcl;
            }
            else
            {
                if(s1.isEmpty())
                break;
                temp=s1.topp();
                s1.pop();
                cout<<temp->info<<" ";
                temp=temp->rcl;
            }
        }
    }

    void preorder()
    {
        //NLR
        stk s1;
        s1.push(root);
        while(!s1.isEmpty())
        {
            root=s1.topp();
            cout<<root->info<<" ";
            s1.pop();
            if(root->rcl)
            {
                s1.push(root->rcl);
            }
            if(root->lcl)
            {
                s1.push(root->lcl);
            }
        }
    }

    void postorder()
    {
        stk s1;
        node *p=root;
        node *last=NULL;
        while(p!=NULL && !s1.isEmpty())
        {
            if(p!=NULL)
            {
                s1.push(p);
                p=p->lcl;
            }
            else
            {
                p=s1.pop();
                if(p->rcl && p->rcl!=last)
                {
                    s1.push(p);
                    p=p->rcl;
                }

                else
                {
                    cout<<p->info<<"->";
                    last=p;
                    p=NULL;
                }
            }
        }
    }
};

int main()
{
    BT b1;
    //node *root=NULL;
    b1.create();
    b1.inorder();
    b1.preorder();
    b1.postorder();
    return 0;
}