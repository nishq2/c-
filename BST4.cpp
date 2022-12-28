#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *left;
    Node *right;
    Node(int ele)
    {
        left = NULL;
        right = NULL;
        info = ele;
    }
};

Node* Insert(Node *root, int data)
{
    // Node *temp = new Node(data);
    if (root == NULL)
    {
        // root=temp;
        return new Node(data);
    }
    else if (data > root->info)
    {
        root->right=Insert(root->right, data);
    }
    else if(data < root->info)
    {
        root->left=Insert(root->left, data);
    }
    return root;
}

void Inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->info << "  ";
    Inorder(root->right);
}

void Search(Node *root,int ele){
    if(!root){
        cout<<"Not Found";
        return;
    }
    if(root->info==ele){
        cout<<"Element Found";
        return;
    }
    else if(root->info > ele){
        Search(root->left,ele);
    }
    else{
        Search(root->right,ele);
    }
}
Node* minVal(Node *root)
{
    Node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
Node* maxVal(Node *root)
{
    Node *temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}
Node* deleteBST(Node *root, int val)
{
    if(root==NULL)
    return root;
    if(root->info==val)
    {
        //0 child
    if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }
        //1 child- right child
    if(root->right!=NULL && root->left==NULL)
    {
        Node *temp=root->right;
        delete root;
        return temp;
    }
        //1 child- left child
     if(root->right==NULL && root->left!=NULL)
    {
        Node *temp=root->left;
        delete root;
        return temp;
    }

        //2 child
    if((root->right!=NULL) && (root->left!=NULL))
    {
        int mini= minVal(root->right)->info;
        root->info=mini;
        root->right=deleteBST(root->right,mini);
        return root;
    }
    }
    else if(root->info>val)
    {
        root->left=deleteBST(root->left,val);
        return root;
    }
    else
    {
        root->right=deleteBST(root->right,val);
        return root;
    }
}
    Node* suc(Node *root, int d)
    {
        Node *succ=NULL;
       while(root!=NULL)
       {
        if(root->info<=d)
        {
            root=root->right;
        }
        else
        {
            succ=root;
            root=root->left;
        }
       }
       return succ;
    }

    Node* pre(Node *root, int d)
    {
        Node *pred=NULL;
        while(root!=NULL)
        {
            if(root->info>=d)
            {
                root=root->left;
            }
            else
            {
                pred=root;
                root=root->right;
            }
        }
        return pred;
    
}
//}

int main()
{
    Node *root = NULL;
    root=Insert(root,15);
    Insert(root, 10);
    Insert(root, 20);
    Inorder(root);
    Search(root,20);
    cout<<endl;
    cout<<"Min value is "<<minVal(root)->info<<endl;
    cout<<"Max value is "<<maxVal(root)->info<<endl;
    root= deleteBST(root,10);
    Inorder(root);
    cout<<"Sucessor: "<<suc(root,10)->info<<endl;
    cout<<"Predecessor: "<<pre(root,10)->info<<endl;
    return 0;
}