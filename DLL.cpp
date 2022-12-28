//doubly linked list
#include<iostream>
using namespace std;
class node
{
    public:
    node* next;
    node* prev;
    int data;

    node()
    {
        next=NULL;
        prev=NULL;
        data=0;
    }
};

class DLL
{
    public:

    //insert at beg
    node* insb(node* head)
    {
        node *temp=new node;
       
        if(head==NULL)
        {
            temp->prev=NULL;
            head=temp;
        }
        else
        {
            head->prev=temp;
            head=temp;
        }
        return head;
    }
//end insert
    // node* inse(node *head)
    // {

    // }
    void display(node* head)
    {
        node *ptr=head;
        if(head==NULL)
        {
            cout<<"List does not exist"<<endl;
            return;
        }
        else
        {
            cout<<"Values: "<<endl;
            while(ptr->next!=NULL)
            {
                cout<<ptr->data<<" "<<endl;
                ptr=ptr->next;
            }
        }
    }
};

int main()
{
    DLL d;
    node n1= new node();
     cout<<"Val?"<<endl;
        cin>>n1->data;
    d.insb(n1);
    d.display(n1);
    return 0;
}