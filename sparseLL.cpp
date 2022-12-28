//sparse matrix linked list
#include<iostream>
using namespace std;

class node
{
    public:
    node *next;
    int r;
    int c;
    int v;
    node()
    {
        next=NULL;
    }
};

class SpLL
{
    public:
    node* represent(node *head, int row, int col, int info)
    {
        node *temp=new node;
        temp->r=row;
        temp->c=col;
        temp->v=info;
        if(head==NULL)
        {
            head=temp;
            return head;
        }
        else
        {
            node *ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;

            return head;
        }
    }

    void display(node *head)
    {
        if(head==NULL)
        {
            cout<<"Doesn't exist"<<endl;
            return;
        }

        node *ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->r<<" "<<ptr->c<<" "<<ptr->v<<" ";
            ptr=ptr->next;
        }

    }

    node* concat(node *head, node *head1)
    {
        node *temp=head1;
        node *ptr=head;
        while(ptr!=NULL)
        {
            temp->r=ptr->c;
            temp->c=ptr->r;
            temp->v=ptr->v;

            head1=represent(temp,ptr->r,ptr->c,ptr->v);

            ptr=ptr->next;
        }

        head1=sortRow(temp);
        return head1;
    }

    node* sortRow(node *head1)
    {
        node *t=head1;
        if(head1==NULL)
        {
            return NULL;
        }

        while(t!=NULL)
        {
            node *t2=t->next;
            while(t2!=NULL)
            {
                if(t2->r<t->r)
                {
                swap(t->r,t2->r);
                swap(t->c,t2->c);
                swap(t->v,t2->v);
                }

                t2=t2->next;
            }
        }
        return head1;
    }
};

int main()
{
    SpLL s1;
    node *head=NULL;
    node *head1=NULL;
    int i,j, a[10][10];
    int m,n;
    int ele;
    cout<<"Enter dimensions"<<endl;
    cin>>m>>n;
    cout<<"Enter elements"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
           cin>>ele;
           if(ele==0)
           {
            continue;
           } 
           else
           {
            head=s1.represent(head,i,j,ele);
           }
        }
    }

    s1.display(head);
    head1=s1.concat(head,head1);
    s1.display(head1);
    return 0;
}