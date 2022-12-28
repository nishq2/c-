#include<iostream>
#include<queue>
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

class que
{
    public:
    int r;
    int f;
    node *q[MAX];
    que()
    {
        r=f=-1;
    }

    void push(node *x)
    {
        if(r==MAX-1)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        else
        q[++r]=x;
        return;
    }

    node* pop()
    {
        if(r==f || r==-1)
        {
            cout<<"Empty queue"<<endl;
            return NULL;
        }
        else
        return q[f++];
    }

    // node* rear()
    // {
    //     return q[r];
    // }

    node* front()
    {
        //cout<<q[++f]<<endl;
        return q[f+1];
    }

    bool isEmpty()
    {
        return r==-1 || r==f;
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
        stk s1;
        node *temp=root;
        if(temp==NULL)
        return;

        while(true)
        {
            if(temp!=NULL)
            {
                s1.push(temp);
                temp=temp->lcl;
            }
            else
            {
                temp=s1.topp();
                s1.pop();
                cout<<temp->info<<"->";
                temp=temp->rcl;
            }
        }
    }

    void preorder()
    {
        stk s1;
        s1.push(root);
        while(!s1.isEmpty())
        {
            cout<<endl;
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
   if (root == NULL)
        return;
    //stack<node*> S;
    stk s1;
    s1.push(root);
    node* prev = NULL;
    while (!s1.isEmpty()) {
        node* current = s1.topp();
        if (prev == NULL || prev->lcl == current
            || prev->rcl == current) {
            if (current->lcl)
                s1.push(current->lcl);
            else if (current->rcl)
                s1.push(current->rcl);
            else {
                s1.pop();
                cout<<current->info<<" ";
            }

        }
 
        else if (current->lcl == prev) {
            if (current->rcl)
                s1.push(current->rcl);
            else {
                s1.pop();
                cout<<(current->info)<<" ";
            }
 
        }
        else if (current->rcl == prev) {
            s1.pop();
            cout<<(current->info)<<' ';
            }
            prev = current;
        }
    
    }

    void level()
    {
       cout<<"Levelorder Traversal >>";
        //queue <node*> q;
        que q;
        q.push(root);
        node *curr;
        while(!q.isEmpty()){
            curr=q.front();
            q.pop();
            cout<<curr->info<<' ';
            if(curr->lcl){
                q.push(curr->lcl);
            }
            if(curr->rcl){
                q.push(curr->rcl);
            }
        }
        cout<<endl;
    
    }

    int depth(node *Node)
    {
        int ldepth, rdepth;
        if(Node==NULL)
        return 0;
        else
        ldepth=depth(Node->lcl);
        rdepth=depth(Node->rcl);
        if(ldepth>rdepth)
        return(ldepth+1);
        else
        return(rdepth+1);
    }

    int leafNode(node *Node)
    {
        if(Node==NULL)
        return 0;
        else if(Node->lcl==NULL && Node->rcl==NULL)
        return 1;
        else
        return leafNode(Node->lcl) + leafNode(Node->rcl);
    }

    bool Parent(node *Node, int ele)
    {
        if(Node->lcl)
        {
            if(Node->lcl->info==ele)
            {
                cout<<"Parent is "<<Node->info<<endl;
                return true;
            }
            else
            {
                return Parent(Node->lcl, ele);
            }
        }
        if(Node->rcl)
        {
            if(Node->rcl->info==ele)
            {
                cout<<"Parent is "<<Node->info<<endl;
                return true;
            }
            else
            {
                return Parent(Node->rcl, ele);
            }
        }
        return false;
    }

    bool Ancestor(node *Node, int ele)
    {
        if(Node==NULL)
        {
            return false;
        }
        if(Node->info==ele)
        return true;

        if((Ancestor(Node->lcl,ele)) || (Ancestor(Node->rcl,ele)))
        {
            cout<<"Ancestors: "<<Node->info<<" ";
            return true;
        }
        //else
        return false;

    }
};

int main()
{
    BT b1;
    //node *root=NULL;
    b1.create();
    //b1.inorder();
    // b1.preorder();
    // b1.postorder();
    // b1.level();
    cout<<"Depth: "<<b1.depth(b1.root)<<endl;
    cout<<"Leaf nodes are "<<b1.leafNode(b1.root)<<endl;
    cout<<"Enter node value"<<endl;
    int val;
    cin>>val;
    b1.Parent(b1.root,val);
    cout<<"Enter node value"<<endl;
    cin>>val;
    b1.Ancestor(b1.root,val);
    return 0;
}