//BST
#include<iostream>
#define MAX 50
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
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

class BST
{
    public:
    void create(node *root)
    {
        cout << "Use -1 to break" << endl;
        cout << "Enter root" << endl;
        root = createTree();
    }
    node *createTree()
    {
        int val;
        cout << ">";
        cin >> val;
        if (val == -1)
            return NULL;
        node *temp = new node;
        temp->data = val;
        cout << "Left child of " << val << endl;
        temp->left = createTree();
        cout << "Right child of " << val << endl;
        temp->right = createTree();
    }

    void inorder(node *root)
    {
        //cout<<"working?"<<endl;
        if(root==NULL)
        return;
        //cout<<"?"<<endl;
        inorder(root->left);
        cout<<root->data<<" ";
        //cout<<"?"<<endl;
        inorder(root->right);
        //cout<<"?"<<endl;
    }

    void inordr(node *root)
    {
        stack s1;
        if(root==NULL)
        return;
        node *temp=root;
        while(true)
        {
            if(temp!=NULL)
            {
                s1.push(temp);
                temp=temp->left;
            }
            else
            {
                if(s1.empty())
                {
                    break;
                }
                else
                {
                    temp=s1.topp();
                    s1.pop();
                    cout<<temp->data<<" ";
                    temp=temp->right;
                }
            }
        }
    }
    bool searchBST(node *root,int x)
    {
        node *temp=root;
        while(temp!=NULL)
        {
            if(temp->data==x)
            {
                return true;
            }
            if(temp->data>x)
            {
                temp=temp->left;
            }
            else
            temp=temp->right;
        }
        return false;
    }

    node* minVal(node *root)
    {
        node *temp=root;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        cout<<temp->data<<endl;
        return temp;
    }

    node*  maxVal(node *root)
    {
        node *temp=root;
        while(temp=temp->right)
        {
            temp=temp->right;
        }
        cout<<temp->data<<endl;
        return temp;
    }

    //predecessor successor

    node* suc(node *root, int d)
    {
        node *succ=NULL;
       while(root!=NULL)
       {
        if(root->data<=d)
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

    node* pre(node *root, int d)
    {
        node *pred=NULL;
        while(root!=NULL)
        {
            if(root->data>=d)
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

    //check if BST or not for every node
    // bool isBST(node *root, node* min, node* max)
    // {
    //     node *a=minVal(root);
    //     node *b=maxVal(root);
    //     if(root==NULL)
    //     return true;

    //     else if(root->data>=min && root->data<=max)
    //     {
    //         bool left=isBST(root->left,a,root->data);
    //         bool right=isBST(root->right,root->data,b);
    //         return left && right;
    //     }
    //     else
    //     return false;
    // }
    // void issBST(node *root)
    // {

    // }

};

int main()
{
    BST b1;
    node *root=NULL;
    b1.create(root);
    cout<<"Inorder"<<endl;
    b1.inorder(root);
    b1.inordr(root);
    cout<<"Enter value"<<endl;
    int val;
    cin>>val;
    b1.searchBST(root,val);
//    node *c=b1.minVal(root);
//     node *d=b1.maxVal(root);
    cout<<"Enter value"<<endl;
    int a;
    cin>>a;
    b1.suc(root,a);
    cout<<"Enter value"<<endl;
    int b;
    cin>>b;
    b1.pre(root,b);
    //b1.isBST(root,c,d);
    return 0;
}