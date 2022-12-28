#include<iostream>
using namespace std;

class node
{
    public:
    node* next;
    node* prev;
    int info;
    node()
    {
        next=NULL;
        prev=NULL;
    }
};

class DLL
{
    public:
    // i.) Insert an element at the rear end of the list
    node* append(node *head)
    {
        node *temp=new node;
        node *ptr;
        cout<<"Enter value"<<endl;
        cin>>temp->info;
        if(head==NULL)
        {
            head=temp;
            return head;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->prev=ptr;
            return head;
        }
    }

    // ii.) Delete an element from the rear end of the list
    void deleteEnd(node *head)
    {
        node *ptr;
        if(head==NULL)
        {
            cout<<"List doesn't exist"<<endl;
            return;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->prev->next=NULL;
            delete(ptr);
           // return head;
        }
    }
// iii.) Insert an element at a given position of the list

    node* insPos(node *head)
    {
        int pos, count=1;
        node *ptr;
        node *temp=new node;
        cout<<"Enter val"<<endl;
        cin>>temp->info;
        cout<<"Enter the position"<<endl;
        cin>>pos;
        if(pos==1)
        {
            head=temp;
            return head;
        }
        else
        {
            ptr=head;
            while(count<pos-1)
            {
                ptr=ptr->next;
                count++;
            }
            if(ptr->next==NULL)
            {
                ptr->next=temp;
                temp->prev=ptr;
            }
            else
            {
                temp->next=ptr->next;
                ptr->next->prev=temp;
                ptr->next=temp;
                temp->prev=ptr;
            }
            return head;
        }
    }
// iv.) Delete an element from a given position of the list

   void deletePos(node *head)
    {
        node *temp, *ptr;
        int pos;
        cout<<"enter the position for the element to be deleted"<<endl;
        cin>>pos;
        if(pos==1)
        {
            temp=head;
            head=head->next;
            head->prev=NULL;
            delete(temp);
        }
        temp=head;
        while(pos>1)
        {
            temp=temp->next;
            pos--;
        }
        if(temp->next==NULL)
        {
            
        }
        else
        {
            ptr=NULL;
            ptr=temp->prev;
            ptr->next=temp->next;
            temp->next->prev=ptr;
            delete(temp);
        }
       // return head;
    }

    // v.) Insert an element after another element
    node *insAfter(node *head)
    {
        node *temp=new node;
        node *ptr;
        int ele;
        bool found;
        cout<<"Enter the value"<<endl;
        cin>>temp->info;
        cout<<"Enter the element to be inserted after"<<endl;
        cin>>ele;
        ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->info==ele)
            {
                ptr->next=temp;
                temp->prev=ptr;
                found=true;
                break;
            }
            ptr=ptr->next;
        }       
        if (found==false)
        {
            cout<<"element doesn't exist"<<endl;
        }
        return head;
    }
    
    // vi.) Insert an element before another element
    node *insBefore(node *head)
    {
        int ele;
        node *temp=new node;
        node *ptr;
        bool found;
        cout<<"Enter the value"<<endl;
        cin>>temp->info;
        cout<<"Enter the element to be inserted before"<<endl;
        cin>>ele;
        ptr=head;
        if(ptr->info==ele)
        {
            temp->next=head;
            head->prev=temp;
            head=temp;
            return head;
        }
        else
        {
            node* curr;
            curr=head;
            while(curr->next!=NULL)
            {
                if(curr->next->info==ele)
                {
                    temp->next=curr->next;
                    curr->next->prev=temp;
                    curr->next=temp;
                    temp->prev=curr;
                    found=true;
                    break;
                }
            }
            if(found==false)
            {
                cout<<"Element doesn't exist"<<endl;
            }
            return head;
        }
    }
    // vii.) Traverse the list
    void display(node *head)
    {
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->info<<" ";
            temp=temp->next;
        }
        cout<<" "<<endl;
    }
// viii.) Reverse the list
    node* reverss(node *head)
    {
        node *ptr1=head;
        node *ptr2=ptr1->next;
        ptr1->next=NULL;
        ptr1->prev=ptr2;
        while(ptr2!=NULL)
        {
            ptr2->prev=ptr2->next;
            ptr2->next=ptr1;
            ptr1=ptr2;
            ptr2=ptr2->prev;
        }
        head=ptr1;
        return head;
    }

};

int main()
{
    DLL d1;
    node *head=NULL;
    int x;
    cout<<"Choose the option you wish to implement"<<endl;
    do
    {
        cout<<"1.Insert at tail\n2.Delete from rear\n3.Insert at a given position\n4.Delete from a given pos\n5.Insert after an ele\n6.Insert before an element\n7.To display\n8.To reverse\n9.To exit\n"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
            head= d1.append(head);
            break;

            case 2:
            d1.deleteEnd(head);
            break;

            case 3:
            head=d1.insPos(head);
            break;

            case 4:
            d1.deletePos(head);
            break;

            case 5:
            head=d1.insAfter(head);
            break;

            case 6:
            head=d1.insBefore(head);
            break;

            case 7:
            d1.display(head);
            break;

            case 8:
            head= d1.reverss(head);
            break;

            default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }while(x!=9);
    return 0;
}
