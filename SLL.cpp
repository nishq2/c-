#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    int data;
    Node *next; //points to the obj of node type only
    Node()
    {
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k, int d)
    {
        key=k;
        data=d;
    }
};

class SLL
{
    public:
    Node* head; //first node 
    SLL()
    {
        head=NULL;
    }
    SLL(Node *n)
    {
        head=n; //passing node by address ie head can point to newly passed node    
    }
    
    Node* nodeExists(int k)
    { //node exists or not using key value
        Node *temp=NULL;
        Node *ptr=head; //to traverse the list
        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp=ptr;
            }
            ptr= ptr->next;
        }
        return temp;
    }

    //2.Append a node to the list-insert at the end
    void appendNode(Node *n)
    {   //accessing the value of n
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node already exists with key value: "<<n->key<<" Append another node with different  value: "<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Node appended"<<endl;
            }
            else
            {
                Node *ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr= ptr->next;
                }
                ptr->next=n; //we know that ptr stores the address of the last node so n that is the pointer value to be inserted at the end
                cout<<"Node appended"<<endl;
            }
        }
    }

    //3.Prepend node- insert at beginning
    void prependNode(Node *n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node already exists with key value: "<<n->key<<" Append another node with different  value: "<<endl;
        }
        else 
        {
            n->next=head;
            head=n;
            cout<<"Node prepended"<<endl;
        }
    }
    //4.Insert at a particular position  
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr= nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"No node exists with key value"<<k<<endl;
        }
        else
        {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node already exists with key value: "<<n->key<<" Append another node with different  value: "<<endl;
        }
        else
        {
            n->next=ptr->next; //n newly created node should have the same next address as its preceeding node
            ptr->next=n;
            cout<<"Node inserted"<<endl;
        }
        }
    }

    //5.delete node by unique key
    void deleteNode(int k)
    {
        if(head==NULL)
        {
            cout<<"Singly linked list is already empty, can't delete"<<endl;
        }
        else if(head!=NULL)
        {
            if(head->key==k)
            {
               head=head->next;
               cout<<"Node unlinked with key value: "<<k<<endl;
            }
            else
            {
                Node* temp=NULL;
                Node* prevptr=head;
                Node* currentptr= head->next;
                while(currentptr!=NULL)
                {
                    if(currentptr!=NULL)
                    {
                        temp=currentptr;
                        currentptr=NULL;
                    }
                    else
                    {
                        prevptr=prevptr->next;
                        currentptr=currentptr->next;
                    }
                }
                if(temp!=NULL)
                {
                    prevptr->next=temp->next;
                    cout<<"Node unlinked with key values: "<<k<<endl;
                }
                else
                {
                    cout<<"Node doesn't exist with key value: "<<k<<endl;
                }
            }
        }
    }

    //6. update value by key
    void updateNodeByKey(int k, int d)
    {
        Node *ptr=nodeExists(k);
        if(ptr!=NULL)
        {
            ptr->data=d;
            cout<<"Data updated successfully"<<endl;
        }
        else
        {
            cout<<"Node doesn't exist with key value: "<<k<<endl;
        }
    }

    //7.diplay the list
    void printList()
    {
        if(head==NULL)
        {
            cout<<"No nodes in the Singly Linked List"<<endl;
        }
        else
        {
            cout<<"\n"<<"SLL values: ";
            Node* temp=head;
            while(temp!=NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<")-->";
                temp=temp->next;
            }
        }
    }
};

int main()
{
    SLL s;
    int x;
    int key1,k1,data1;
    do
    {
        cout<<"\nSelect the operation you wish to perform"<<endl;
        cout<<"1.Append node"<<endl;
        cout<<"2.Prepend node"<<endl;
        cout<<"3.Insert at a specific position"<<endl;
        cout<<"4.Delete a node"<<endl;
        cout<<"5.Update the value of a node"<<endl;
        cout<<"6.Display the Singly Linked List"<<endl;
        cout<<"7.To exit"<<endl;
        cin>>x;
        Node *n1= new Node(); //global- exists in heap memory
        switch(x)
        {
            case 1:
            cout<<"Enter key and data to be appended"<<endl;
            cin>>key1>>data1;
            n1->key=key1;
            n1->data=data1;
            s.appendNode(n1);
            break;

            case 2:
            cout<<"Enter key and data to be prepended"<<endl;
            cin>>key1;
            cin>>data1;
            s.prependNode(n1);
            break;

            case 3:
            cout<<"Enter key of existing node:"<<endl;
            cin>>k1;
            cout<<"Enter key and data of the new node"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.insertNodeAfter(k1,n1);
            break;

            case 4:
            cout<<"Enter key value to be deleted"<<endl;
            cin>>k1;
            s.deleteNode(k1);
            break;

            case 5:
            cout<<"Enter key and data to be updated"<<endl;
            cin>>key1;
            cin>>data1;
            s.updateNodeByKey(key1,data1);
            break;

            case 6:
            s.printList();
            break;

            default:
            cout<<"Invalid option"<<endl;
            break;
        }
    }while(x!=7);
    
    return 0;
}