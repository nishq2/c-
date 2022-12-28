#include<iostream>
using namespace std;

class node
{
    public:
    int coff;
    int expo;
    node *next;
    node *prev;
    node(int c, int e)
    {
        coff=c;
        expo=e;
        next=prev=NULL;
    }
};

class DLL
{
    public:
    node* readpoly(node *p1)
    {
        int c,e;
        while(true)
        {
        cout<<"Enter coff and expo"<<endl;
        cin>>c>>e;
        if(c=e=-1)
        {
            break;
        }
        attach(c,e,p1);
        }
    }

    node* attach(node *p1,int c, int e)
    {
        node *temp=new node;
        temp->coff=c;
        temp->expo=e;
        temp->next=temp->prev=NULL;
        node *ptr=p1;
        if(p1==NULL)
        {
            p1=temp;
            return p1;
        }
        else
        {
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->prev=ptr;
            return head;
        }
    }

    node* add(node *p1, node *p2)
    {
        node *p3=NULL;
        int c,e;
        int x;
        if(p1==NULL)
        {
            return p2;
        }

        if(p2==NULL)
        {
            return p1;
        }

        if(p1=NULL && p2!=NULL)
        {
            if(p1->expo==p2->expo)
            {
                x=1;
            }
            if(p1->expo>p2->expo)
            x=2;

            else
            x=3;

            switch(x)
            {
                case 1:
                c=p1->coff+p2->coff;
                p3=attach(c,p1->expo,p3);
                p1=p1->next;
                p2=p2->next;
                break;

                case 2:
                p3=attach(p1->coff, p1->expo,p3);
                p1=p1->next;
                break;

                default:
                p3=attach(p2->coff,p2->expo,p3);
                p2=p2->next;
                break;
            }
        }

        while(p2!=NULL)
        {
            p3=attach(p2->coff,p2->expo,p3);
        }

        while(p1!=NULL)
        {
            p3=attach(p1->coff,p1->expo,p3);
        }

        return p3;
    }

    void display(node *p3)
    {
        node *t=p3;
        while(t!=NULL)
        {
            cout<<t->coff<<"x^"<<t->expo<<"+"<<" "<<endl;
            t=t->next;
        }
    }
};

int main()
{
    node *p1=NULL;
    node *p2=NULL;
    node *p3=NULL;
    DLL d1;
    p1=d1.readpoly(p1);
    p2=d1.readpoly(p2);
    p3=d1.add(p1,p2);
    d1.display(p3);
}