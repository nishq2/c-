//dcll
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

class CDLL
{
    public:
    //i) Insert an element into a doubly linked circular list
    //ii) Delete an element from a doubly linked circular list.
    node* append(node *tail)
    {
        node *temp=new node;
        cout<<"Enter val"<<endl;
        cin>>temp->info;
        //node *ptr;
        if(tail==NULL)
        {
            temp->prev=temp;
            temp->next=temp;
            tail=temp;
            return tail;
        }
        else
        {
           // ptr=tail->next;
           temp->next=tail->next;
            tail->next->prev=temp;
            tail->next=temp;
            temp->prev=tail;
            //ptr->prev=temp;
            
            tail=temp;
            return tail;
        }
    }

    void deleteNode(node *tail)
    {
        node *temp2=tail;
        node *temp;
        temp=tail->prev;
        temp->next=tail->next;
        tail->next->prev=temp;
        delete(temp2);
    }

    void display(node *tail)
    {
        node *ptr;
        ptr=tail->next;
        node* head= tail->next;
        if(tail==NULL)
        {
            cout<<"List doesn't exist"<<endl;
            return;
        }
        else{
            do
            {
                cout<<ptr->info<<" ";
                ptr=ptr->next;
            }while(ptr!=head);

            cout<<" "<<endl;
        }
    }
};

int main()
{
    CDLL c1;
    node* tail=NULL;
    int x;
    cout<<"Select the option you wish to implement"<<endl;
    do
    {
        cout<<"1.to insert\n2.To delete\n3.To display\n4.To exit\n"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
            tail=c1.append(tail);
            break;

            case 2:
            c1.deleteNode(tail);
            break;

            case 3:
            c1.display(tail);
            break;

            default:
            cout<<"EXITING..."<<endl;
            break;
        }
    } while (x!=4);
    return 0;
}