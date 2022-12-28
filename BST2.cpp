#include<iostream>
using namespace std;
class node
{
    public:
    node *left;
    node *right;
    int data;
    node()
    {
        //this->data=d;
        left=NULL;
        right=NULL;
    }

    node* insertIntoBST(node*,int);
    void takeInput(node*);
};

class BST
{
    public:
    node *root;
    // BST()
    // {
    //     root=NULL;
    // }
    //takeInput(node*);
    bool isEmpty()
    {
        if(root==NULL)
        return true;
        else
        return false;
    }

    void insertNode(node *newNode)
    {
        if(root==NULL)
        {
            root=newNode;
            cout<<"Value inserted"<<endl;
        }
        else
        {
            node *temp=root;
            while(temp!=NULL)
            {
                if((newNode->data<temp->data) &&(temp->left==NULL))
                {
                    temp->left=newNode;
                    break;
                }
                else if(newNode->data<temp->data)
                {
                    temp=temp->left;
                }
                // else if(temp->data==newNode->data)
                // {
                //     cout<<"Already exists"<<endl;
                //     return;
                // }
                else if((newNode->data>temp->data) && (temp->right==NULL))
                {
                    temp->right=newNode;
                    break;
                }
                else
                {
                    temp=temp->right;
                }
            }
        }
    }

};
// void takeInput(node* root)
//     {
//         int data;
//         cin>>data;

//         while(data!=-1)
//         {
//            root= insertIntoBST(root,data);
//             cin>>data;
//         }
//     }

//     node* insertIntoBST(node* root, int d)
//     {
//         if(root==NULL)
//         {
//             root=new node(d);
//             return root;
//         }
//         if(d>root->data)
//         {
//             root->right=insertIntoBST(root->right,d);
//         }
//         else
//         root->left=insertIntoBST(root->left,d);

//         return root;
//     }

int main()
{
    BST b1;
    node *newNode= new node;
    int val;
    //takeInput();
    b1.isEmpty();
    do
    {
    cout<<"Insert value"<<endl;
    cin>>val;
    newNode->data=val;
        b1.insertNode(newNode);
    } while (val!=-1);
    
    
    return 0;
}