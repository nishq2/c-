//priority q using csll
#include<iostream>
using namespace std;

class node
{
    public:
    node *next;
    int info;
    int priority;
    node()
    {
        next=NULL;
    }
};

class PQCLL
{
    public:
    node* insend(node *head)
    {
        node *temp=new node;
        cout<<"Enter node value"<<endl;
        cin>>temp->info;
        cout<<"Enter priority"<<endl;
        cin>>temp->priority;
        if(head==NULL)
        {
            head=temp;
            temp->next=head;
            return head;
        }
        else
        {
            node *ptr=head;
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->next=head;

            return head;
        }
    }
    node* delbeg(node *head)
    {
        if(head==NULL)
        {
            cout<<"doesn't exist"<<endl;
            return NULL;
        }
        else
        {
            node *ptr=head;
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            node *temp=head;
            head=head->next;
            ptr->next=head;
            delete(temp);
            return head;
        }
    }

    void sort(node *head)
    {
        int num;
        node *ptr=head;
        node *temp;
        do
        {
            temp=ptr->next;
            do
            {
                if(temp->priority>ptr->priority)
                {
                    num=temp->info;
                    temp->info=ptr->info;
                    ptr->info=num;
                }
                temp=temp->next;
            } while (temp!=head);
            
            ptr=ptr->next;
        } while (ptr->next!=head);
    }

    void display(node *head)
    {
        node *t=head;
        while(t->next!=head)
        {
            cout<<t->info<<"->";
            t=t->next;
        }
        cout<<endl;
    }

};

int main()
{
    PQCLL p1;
    int x;
    node *head=NULL;
    do
    {
        cout<<"1.Insert\n2.Delete\n3.Sort\n4.Display\n";
        cin>>x;
        switch(x)
        {
            case 1:
            head=p1.insend(head);
            break;

            case 2:
            head=p1.delbeg(head);
            break;

            case 3:
            p1.sort(head);
            break;

            case 4:
            p1.display(head);
            break;
        }
    }while(x!=5);
    return 0;
}