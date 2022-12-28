#include<iostream>
using namespace std;

class node
{
    public:
    node* next;
    int info;
    node()
    {
        next=NULL;
    }
};

class SLL
{
    public:
    node* insHead(node *head)
    {
        node *temp=new node;
        cout<<"Enter the data"<<endl;
        cin>>temp->info;
        
        
        if(head==NULL)
        {
            head=temp;
            return head;
        }
        else
        {
            temp->next=head;
            head=temp;
            return head;
        }
    }

    void display(node *head)
    {
        node *temp;
        temp=head;
        if(head==NULL)
        {
            cout<<"List doesn't exist"<<endl;
            return;
        }
        else
        {
            while(temp!=NULL)
            {
                cout<<temp->info<<" ";
                temp=temp->next;
            }
            cout<<" "<<endl;
        }
    }

    node* insTail(node *head)
    {
        node *temp=new node;
        node *ptr;
        cout<<"enter data"<<endl;
        cin>>temp->info;
        ptr=head;
        if(head==NULL)
        {
            head=temp;
            return head;
        }
        else
        {
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            return head;
        }
    }

    void deleteNode(node *head)
    {
        node *temp;
        int pos;
        cout<<"Enter the position to be deleted"<<endl;
        cin>>pos;
        if(head==NULL)
        {
            cout<<"List doesn't exist"<<endl;
            return;
        }
        else if(pos==1)
        {
            temp=head;
            head=head->next;
            delete(temp);
        }
        else
        {
            node *curr, *prev;
            curr=head;
            prev=NULL;
            int count=1;
            while(count<pos)
            {
                prev=curr;
                curr=curr->next;
                count++;
            }
            prev->next=curr->next;
            delete(curr);
        }
        //return head;
    }

    node* reverse(node *head)
    {
        node *forward;
        node *curr, *prev;
        curr=head;
        prev=NULL;
        forward=NULL;
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        head=prev;
        return prev;
    }

    node* middle(node* head)
    {
        node *temp;
        int len=0, count=0;
        temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        int ans=len/2;
        node *ptr;
        ptr=head;
        while(count<ans)
        {
            ptr=ptr->next;
            count++;
        }
        cout<<ptr->info<<endl;
        return ptr;
    }
};


int main()
{
    node *head=NULL;
    SLL s1;
    int x;
    cout<<"option?"<<endl;
    do
    {
        cout<<"1.insert at head\n2.display\n3.insert at tail\n4.delete a node\n5.reverse\n6.middle of SLL\n"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
            cout<<head<<endl;
            head=s1.insHead(head);
            cout<<head;
            break;

            case 2:
            s1.display(head);
            break;

            case 3:
            head=s1.insTail(head);
            break;

            case 4:
            s1.deleteNode(head);
            break;

            case 5:
            head=s1.reverse(head);
            break;

            case 6:
            s1.middle(head);
            break;

            default:
            cout<<"Invalid option"<<endl;
            break;
        }
    } while (x!=7);
    return 0;
}