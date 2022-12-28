//reverse in k groups
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

class SLL
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
            temp->next=head;
            head=temp;
            return head;
        }
    }

    node *reverseK(node *head, int k)
    {
        // int k;
        node *curr, *prev, *forward;
        //step 1: base case

        if(head==NULL)
        {
            return NULL;
        }
        //step 2: reverse in k groups

            curr=head;
            prev=NULL;
            forward=NULL;
            int count=0;
            while(curr!=NULL && count<k)
            {
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
                count++;
            }

       //step 3: repeat for each k nodes so recursion

       if(forward!=NULL)
       {
         head->next=reverseK(forward, k);
       }
       //step 4: return head of reversed list, since reversed prev becomes the head as in opp order

       return prev;
    }

    void display(node *head)
    {
        node *temp;
        temp=head;
        if (head==NULL)
        {
            cout<<"list doesn't exist"<<endl;
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
    SLL s1;
    node *head=NULL;
    int k;
    int x;
    do
    {
       cout<<"1.To prepend\n2.reverse in k groups\n3.display\n";
       cin>>x;
       switch(x)
       {
        case 1:
        head= s1.prepend(head);
        break;

        case 2:
        cout<<"Enter the no of elements in each group"<<endl;
        cin>>k;
        head=s1.reverseK(head, k);
        break;

        case 3:
        s1.display(head);
        break;

        default:
        cout<<"invalid option"<<endl;
        break;

       }
    } while (x!=4);

    return 0;
}
