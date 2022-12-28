//circular linked list

#include<iostream>
using namespace std;

class node
{
    public:
    node* next;
    int info;
};

class CLL
{
    public:
    
    node *head;
    node *last;
    CLL()
    {
        head=NULL;
        last=NULL;
    }
//insert at last using last pointer
    node* insel()
    {
        node *temp=new node;
        cout<<"val?"<<endl;
        cin>>temp->info;
        if(last==NULL)
        {
            last=temp;
            temp->next=last;
        }

        else
        {
            temp->next=last->next;
            last->next=temp;
            last=temp;
        }
        return last;
    }

    //insert at beginning using last ptr

    node* insbl()
    {
        node *temp=new node;
        cout<<"Val?"<<endl;
        cin>>temp->info;
        if(last==NULL)
        {
            last=temp;
            last->next=last;
        }
        else
        {
            temp->next=last->next;
            last->next=temp;
        }
        return last;
    }

    //insert at end using head ptr

    node* inseh()
    {
        node *temp=new node;
        node *ptr;
        cout<<"Val?"<<endl;
        cin>>temp->info;
        if(head==NULL)
        {
            head=temp;
            temp->next=head;
        }
        
        else
        {
            ptr=head;
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
                ptr->next=temp;
                temp->next=head;
            
            return head;
        }
    }

    //insert at beginning using head ptr

    node* insbh()
    {
        node *temp=new node;
        node* ptr;
        cout<<"Val?"<<endl;
        cin>>temp->info;
        if(head==NULL)
        {
            head=temp;
            temp->next=head;
        }
        
        else
        {
            temp->next=head;
            
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            head=temp;
        }
        return head;
    }

    void display()
    {
        node* temp=head;
        if(head==NULL)
        {
            cout<<"List doesn't exist"<<endl;
            return;
        }
        else
        {
            cout<<"SLL values: "<<endl;
            while(temp->next!=head)
            {
                cout<<temp->info<<"->"<<endl;
                temp=temp->next;
            }
        }
    }
};

int main()
{
    CLL c;
    int x;
    
    do
    {
        cout<<"1.Insert at last using last pointer"<<endl;
        cout<<"2.Insert at beginning using last ptr"<<endl;
        cout<<"3.Insert at end using head ptr"<<endl;
        cout<<"4.insert at beginning using head ptr"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Exit"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
            c.insel();
            break;

            case 2:
            c.insbl();
            break;

            case 3:
            c.insbh();
            break;

            case 4:
            c.inseh();
            break;

            case 5:
            c.display();
            break;

            default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }while(x!=6);

    return 0;
}