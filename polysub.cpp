//poly sub
#include<iostream>
using namespace std;

class node
{
    int coff;
    int expo;
    node* next;
    node *head;
    public:
    poly()
    {
        head==NULL;
    }
    void input()
    {
        while(true)
        {
            int c, e;
            cout<<"Enter coeffecient and exponent(Enter -999 to stop)"<<endl;
            cin>>c>>e;
            if(c=-999)
            {
                break;
            }
            else
            attach(c,e);
        }
    }

    void attach(int coef, int exp)
    {
        node *temp=new node;
        temp->coff=coef;
        temp->expo=exp;
        temp->next=NULL;
        node *ptr=head;
        if(head==NULL)
        {
            head=temp;
            return;
        }
        else
        {
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }

    node* polysub(node* head1, node* head2)
    {
        node* ptr1=head1;
        node* ptr2=head2;
        node* head3=NULL;
        //int s;
        if(ptr1==NULL)
        return ptr2;

        else if(ptr2==NULL)
        return ptr1;

        else
        {
            if(ptr1->expo>ptr2->expo)
            {
                head3= attach(ptr1->coff, ptr1->expo);
                ptr1=ptr1->next;
            }

            else if(ptr1->expo==ptr2->expo)
            {
                head3= attach((ptr1->coff)-(ptr2->coff), ptr1->expo);
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            else
            {
                head3= attach(ptr2->coff, ptr2->expo);
                ptr2=ptr2->next;
            }
        }
        while(ptr1==NULL)
        {
            while(ptr2!=NULL)
            {
                attach(ptr2->coff, ptr2->expo);
                ptr2=ptr2->next;
            }
        }
        while(ptr2==NULL)
        {
            while(ptr1!=NULL)
            {
                attach(ptr1->coff, ptr2->expo);
                ptr1=ptr1->next;
            }
        }
        return head;
        display(head3);
    }

    void display(node*ptr)
    {
        //node *ptr=new node;
        ptr=head;
        if(head==NULL)
        {
            cout<<"Zero polynomial"<<endl;
        }
        else
        {
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            cout<<ptr->coff<<"x"<<ptr->expo<<"+"<<endl;
        }
        
    }
};

int main()
{
    node*p1, *p2, *res;
    cout<<"Enter for polynomial 1:"<<endl;
    p1=input();
    cout<<"Enter for polynomial 2:"<<endl;
    p2=input();
    res=polysub(p1,p2);
    return 0;
}