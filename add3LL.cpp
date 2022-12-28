//stacks linked list
// Let X = (x1, x2….xn) and Y = (y1, y2….yn) be 2 linked lists. Assume that, in each list, 
// the nodes are in non-decreasing order of the data field values. Write an algorithm to 
// merge two lists to obtain a new linked list Z in which the nodes are also in the non decreasing order. Following the merge, X and Y do not exist as individual lists. Each 
// node initially in X or Y is now in Z. Do not use additional nodes.

#include<iostream>
using namespace std;

class node
{
    public:
    node *next;
    int info;

    node()
    {
        next=NULL;
    }
};

class LL
{
    public:
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

    void sort(node *head)
    {
        node *t=head, *t2, *min;
        //int temp;
        while(t!=NULL)
        {
            min=t;
            t2=t->next;
            while(t2!=NULL)
            {
                if(t2->info<min->info)
                min=t2;
                t2=t2->next;
            }
            if(min!=t)
            {
                swap(min->info,t->info);
            }
            t=t->next;
        }
    }

    node* concatLL(node *head, node *head1)
    {
        if(head==NULL)
        return head1;

        if(head1==NULL)
        return head;
        else
        {
        node *ptr=head;
        
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=head1;
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
};

int main()
{
    int x;
    LL l1;
    node *head=NULL;
    node *head1=NULL;
    node *head2=NULL;
    do
    {
        cout<<"1.Insert1\n2.insert2\n3.Concat\n4.Sort\n5.Display\n6.Exit"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
            head=l1.insTail(head);
            break;

            case 2:
            head1=l1.insTail(head1);
            break;

            case 3:
            head2=l1.concatLL(head, head1);
            break;

            case 4:
            l1.sort(head);
            break;

            case 5:
            l1.display(head);
            break;
        }
    }while(x!=5);
    return 0;
}