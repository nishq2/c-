//binary tree recursion
#include<iostream>
using namespace std;

class node
{
    public:
    node *lcl;
    node* rcl;
    int info;
    node(int i)
    {
        this->info=i;
        lcl=NULL;
        rcl=NULL;
    }
};

    void BT()
    {
        cout<<"Enter value"<<endl;
        int info;
        cin>>info;
       // cin>>root->info;
         root=new node(info);
        //same as cin>>root->info but since root declared in () and is an object  instead of instance variable
        if(info==-1)
        {
            return;
        }
        else
        {
            cout<<"Insert data to insert left of "<<info<<endl;
            //cin>>info;
            root->lcl=BT(root->lcl);
            cout<<"Insert data to insert right of "<<info<<endl;
            root->rcl=BT(root->rcl);
        }
        //return root;
    }


int main()
{
    //BT b1;
    node *root=NULL;
    root= BT(root);
    return 0;
}