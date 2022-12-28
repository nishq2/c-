//concatenate two dll
#include<iostream>
using namespace std;

class node
{
    public:
    node *next;
    node *prev;
    int info;
    node()
    {
        next=NULL;
        prev=NULL;
    }
};

class DLL
{
    public:
    node* prepend(node *head)
    {
        node *temp=new node;
        cout<<"Enter value"<<endl;
        cin>>temp->info;
        if(head==NULL)
        {
            head=temp;
            return head;
        }
        else
        {
            head->prev=temp;
            temp->next=head;
            head=temp;
            return head;
        }
    }

    node* concat(node *head, node *head2)
    {
        node *ptr;
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=head2;
        head2->prev=ptr;
        return head;
    }

    void display(node *head)
    {
    node *ptr;
    if(head==NULL)
    {
        cout<<"List doesn't exist"<<endl;
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->info<<" ";
            ptr=ptr->next;
        }
        cout<<" "<<endl;
    }
    }
};

int main()
{
    int x;
    DLL d1;
    node* head=NULL;
    node *head2=NULL;
    node *head3=NULL;
    cout<<"Choose the option you wish to implement"<<endl;
    do
    {
        cout<<"1.input for list1\n2.input for list 2\n3.To concatenate\n4.To display\n5.To exit"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
            head= d1.prepend(head);
            break;

            case 2:
            head2=d1.prepend(head2);
            break;

            case 3:
            head3=d1.concat(head,head2);
            break;

            case 4:
            d1.display(head);
            break;

            default:
            cout<<"EXITING..."<<endl;
            break;
        }
    }while(x!=5);
    return 0;
}