#include<iostream>
using namespace std;
class node
{
    public:
    node *left;
    node *right;
    int data;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
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

    void takeInput(node *root)
    {
        int data;
        cin>>data;
        while(data!=-1)
        {
            insertBST(root,data);
            cin>>data;
        }
    }

    void insertBST(node *root, int d)
    {
        if(root==NULL)
        {
            root=new node(d);
            return;
        }
        if(d>root->data)
        {
            root->right=insertBST(root->right,d);
        }
        else
        root->left=insertBST(root->left,d);
    }
};

int main()
{
    node *root=NULL;
    cout<<"Enter root value"<<endl;
    takeInput();

    return 0;
}