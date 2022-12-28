//binary tree to dll
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

    void create()
    {
        node *t, *p;
        int x;
        stack s1;
        root=new node;
        cout<<"Enter root value"<<endl;
        cin>>x;
        root->info=x;
        //root->rcl=root->lcl=NULL;
        while(!s1.empty())
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

    void recInorder(node *Root)
    {
        //LNR
        //base case
        if(Root==NULL)
        return;
        
        recInorder(Root->lcl);
        cout<<Root->info<<" ";
        recInorder(Root->rcl);
    }
    void createBT()
    {
        cout<<"Enter root value"<<endl;
        root=createRec();
    }
    node* createRec()
    {
         int val;
        cout << ">";
        cin >> val;
        if (val == -1)
            return NULL;
        node *temp = new node;
        temp->info = val;
        cout << "Left child of " << val << endl;
        temp->lcl = createRec();
        cout << "Right child of " << val << endl;
        temp->rcl = createRec();
    }

    // void BTtoDLL()
    // {
    //     inorder();
    //     prev=NULL;
    //     node *head=root;
    //     if(root==NULL)
    //     return;
    //    BTtoDLL(root->lcl);
    //         //node *temp=root;
    //         if(prev==NULL)
    //         {
    //             head=root;
    //         }
    //         else
    //         {
    //             root->left=prev;
    //             prev->right=root;
    //         }
    //         prev=root;
    //     BTtoDLL(root->rcl);
        

    // }

};

int main()
{
    BT b1;
    int x;
   // node *root=NULL;
    do
    {
        cout<<"1.Iterative creation\n2.Iterative inorder\n3.Recursive creation\n4.Recursive inorder\n5.Exit"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
            b1.create();
            break;

            case 2:
            b1.inorder();
            break;
            //b1.BTtoDLL();
            case 3:
            b1.createBT();
            break;

            case 4:
            b1.recInorder(b1.root);
            break;

            default:
            cout<<"EXITING"<<endl;
            break;
        }
    }while(x!=5);
    return 0;
}