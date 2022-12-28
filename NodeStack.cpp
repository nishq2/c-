#include <iostream>
using namespace std;

class Node{
    public:
    int info;
    Node *next;
    Node(int ele){
        info=ele;
        next=NULL;
    }
};

class NodeStk{
    int top;
    Node *arr[100];
    public:
    NodeStk(){
        top=-1;
    }
    void push(Node *head);
    Node *pop(Node *head);
    void disp();
};

Node *insend(Node *head,int ele){
    Node *temp=new Node(ele);
    if(!head){
        return temp;
    }
    Node *t=head;
    while(t->next){
        t=t->next;
    }
    t->next=temp;
    return head;
}
Node *insbeg(Node *head,int ele)
{
    Node *temp=new Node(ele);
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    return head;
}

void dispList(Node *head){
    if(!head){
        return;
    }
    Node *t=head;
    for(;t;t=t->next){
        cout<<t->info<<"->";
    }
}

void NodeStk::push(Node *x){
    
    if(top==99)
    {
        cout<<"Stack is full"<<endl;
        return;
    }
    else
    arr[++top]=x;
}

Node* NodeStk::pop(Node *head){
    if(top==-1){
        cout<<"Stack empty"<<endl;
        return NULL;
    }
    else
    return arr[top--];
}

void NodeStk::disp(){
    if(top==-1){
       cout<<"Empty Stack";
        return;
    }
    for(int i=0;i<=top;i++){
        cout<<arr[i]->info<<endl;
    }
}

int main(){
    Node *head=NULL;
    NodeStk nstk;
    head=insend(head,1);
    head=insend(head,2);
    head=insend(head,3);
    head=insend(head,4);
    head=insend(head,5);
    head=insend(head,6);
    head=insbeg(head,0);
    head=insbeg(head,7);
    nstk.push(head);
    nstk.push(head);
    nstk.push(head);
    nstk.pop(head);
    nstk.pop(head);
    // nstk.pop(head);
    // nstk.pop(head);
    nstk.disp();
    dispList(head);
    return 0;
}