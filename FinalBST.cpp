#include<iostream>
#define MAX 50
using namespace std;

class node
{
    public:
    node *rcl;
    node *lcl;
    //node *root;
    int info;
    node()
    {
        //this->info=d;
        rcl=NULL;
        lcl=NULL;
        //root=NULL;
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

class BST
{
    public:
    node *root;
    BST()
    {
        root=NULL;
    }
    
    node* insertBST()
    {
        node *temp=new node;
        node *ptr=root;
        cout<<"Enter value"<<endl;
        cin>>temp->info;
        temp->rcl=temp->lcl=NULL;
        if(root==NULL)
        {
            temp=root;
            return root;
        }
        while(ptr!=NULL)
        {
            if((temp->info<ptr->info) && (ptr->lcl==NULL))
            {
                ptr->lcl=temp;
                break;
            }
            else if(temp->info<ptr->info)
            {
                ptr=ptr->lcl;
            }
            else if((temp->info>ptr->info) && (ptr->rcl==NULL))
            {
                ptr->rcl=temp;
                break;
            }
            else if(temp->info>ptr->info)
            {
                ptr=ptr->rcl;
            }

        }
    }

    void inorder(node *Node)
    {
        cout<<"working?"<<endl;
        if(Node==NULL)
        return;
        cout<<"?"<<endl;
        inorder(Node->lcl);
        cout<<Node->info<<" ";
        cout<<"?"<<endl;
        inorder(Node->rcl);
        cout<<"?"<<endl;
    }
    void inorderIt()
    {
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
};
int main()
{
    BST n1;
    int x;
    do
    {
        cout<<"1.Insert\n2.inorder"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
            n1.insertBST();
            break;

            case 2:
            n1.inorder(n1.root);
            break;
        }
    }while(x!=-1);
    return 0;
}