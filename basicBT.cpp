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
    node *root;
    public:
    //creation
    BT()
    {
        root=NULL;
    }

    void createBT()
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
// here always initialise root within the class itself as its difficult to pass root's vvalue from main and in, pre or post order wont work
//passing head/tail value works fine in linked list not here 
    void inorderIterative()
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
        
        if(!root)
        return;
        node *curr=root;
        while(!s1.isEmpty() || curr!=NULL)
        {
            if(curr!=NULL)
            {
                s1.push(curr);
                curr=curr->lcl;
            }
            else
            {
                node *temp=s1.topp()->rcl;
                if(temp==NULL)
                {
                    ///cout<<"pushed rcl"<<endl;
                    temp=s1.topp();
                    s1.pop();
                    //cout<<"Popped"<<endl;
                    cout<<temp->info<<" ";
                    while(!s1.isEmpty() && temp==s1.topp()->rcl)
                    {
                        //cout<<"Working"<<endl;
                        temp=s1.topp();
                        cout<<"Working"<<endl;
                        s1.pop();
                        cout<<temp->info<<" ";
                        
                    }
                }
                else
                curr=temp;
            }
        }
    }
    

};

int main()
{
    BT b1;
    //node *root=NULL;
    b1.createBT();
    b1.inorderIterative();
    b1.preorder();
    b1.postorder();
    return 0;
}
