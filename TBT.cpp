//threaded bt
#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    int lbit;
    int rbit;
    int info;
    node()
    {
        left=right=NULL;
    }
};


class TBT
{
    public:
    node *head;
    TBT()
    {
        head=NULL;
    }
    node* create(node *root)
    {
        char ch;
        do
        {
            node* temp=new node;
            cin>>temp->info;
            temp->left=temp->right=NULL;
            temp->lbit=temp->rbit=0;
            if(root==NULL)
            {
                head=new node;
                head->data=999;
                head->rbit=1;
                head->right=head;
                head->left=root;
                head->lbit=1;
                root->left=head;
                root->right=head;
                return head;
            }

            else
            {
                root=insert(root,temp);
            }

            cout<<"Continue?(y/n)"<<endl;
        } while (ch=='y');
        
        return root;
    }

node* insert(node *root, node *temp)
{
    if(temp->info<root->info)
    {
        if(root->left==NULL)
        {
        root->left=temp;
        temp->left=root->left;
        //temp->right=root;
        temp->right=root;
        root->lbit=1;
        }

        else
        {
            insert(root->left,temp);
        }
        return root;
    }

    if(temp->info>root->info)
    {
        if(root->right==NULL)
        {
            root->right=temp;
            temp->right=root->right;
            temp->left=root;
            root->rbit=1;
        }
        else
        {
            insert(root->right,temp);
        }

        return root;
    }
}

void inorder()
{
    node *t=head->left;
    do
    {
        while(t->lbit!=0)
        {
            t=t->left;
        }
        cout<<t->data<<" ";
        while(t->rbit==0)
        {
            t=t->right;
            if(t==head)
            return;
            cout<<t->info<<" ";
        }
        t=t->right;
    } while (t!=head);
    
}

};

int main()
{
    int x;
    TBT t1;
    node *root=NULL;
    do
    {
        cout<<"1.Insert\n2.Display"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
            root=t1.create(root);
            break;

            case 2:
            t1.inorder();
            break;
        }
    }while(x!=3);
    return 0;
}