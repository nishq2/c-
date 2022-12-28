//Given two singly linked lists, write a user defined function to insert nodes of the second list into first list at alternate position 
//of the first list.

#include<iostream>
using namespace std;
class node
{
    public:
    node *next;
    int info;
    node(int val)
    {
        next=NULL;
        info=val;
    }
};

class SLL
{
    public:
    node *prepend(node *head,int val)
    {
        node *temp=new node(val);
        
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
        node *ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->info<<"->";
            ptr=ptr->next;
        }
    }

    node* concat(node *head, node *head2)
    {
        node *ptr=head;
        node *temp=head2;
        node *p, *q;
        while(ptr!=NULL && temp!=NULL)
        {
            p=ptr->next;
            q=temp->next;
            temp->next=p;
            ptr->next=temp;

            ptr=p;
            temp=q;
        }

        return head;
    }

};

int main()
{
    node *head=NULL;
    node *head2=NULL;
    int x,val;
    SLL s1;
    do
    {
        cout<<"1.Insert1\n2.Alternate\n3.Display\n4.Insert2"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
        cout<<"Enter value"<<endl;
        cin>>val;
         head=s1.prepend(head,val);
            break;

            case 2:
            head=s1.concat(head,head2);
            break;

            case 3:
            s1.display(head);
            //s1.display(head2);
            break;

            case 4:
            cout<<"Enter value"<<endl;
        cin>>val;
         head2=s1.prepend(head2,val);
            break;
        }
    }while(x!=5);
    return 0;
}