#include<iostream>
#include<math.h>
using namespace std;
class node{
    public:
    int exp,coe;
    node *next;
    
    
};

class poly{
    
    public:
    node *p;
    poly(){
        p=NULL;
    }
    void append(int c,int e){
        node *temp=new node;
        temp->coe=c;
        temp->exp=e;
        temp->next=NULL;
        node *t=p;
        if(p==NULL){
            p=temp;
            return ;
            
        }
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=temp;
        
    }

    void readpoly(){
        while(1){
            int coe,exp;
            cout<<"Enter Coefficient and Exponent: ";
            cin>>coe>>exp;
            if(coe==-999){
                break;
            }
            append(coe,exp);
        }
        
    }
    node* addn(node* p1,node* p2){
        int s,c;
        if(p1==NULL)
            return p2;
        if(p2==NULL)
            return p1;
        while(p1!=NULL && p2!=NULL){
            if(p1->exp==p2->exp)
                s=0;
            else if(p1->exp>p2->exp)
                s =1;
            else    
                s=-1;
            switch(s){
            case 0:
                c = p1->coe+p2->coe;
                append(c,p1->exp);
                p1=p1->next;p2=p2->next;
                break;
            case 1:
                append(p1->coe,p1->exp);
                p1=p1->next;
                break;
            default:
                append(p2->coe,p2->exp);
                p2=p2->next;
                break;

            }
            
        }
        
        if(p1==NULL){
            while(p2!=NULL){
                append(p2->coe,p2->exp);
                p2=p2->next;            
            }
        }
        while(p1!=NULL){
                append(p1->coe,p1->exp);
                p1=p1->next;            
        }
        return p;
        
              
    }
    //using recirsion
    node* addre(node* p1, node *p2){
        if(!p1)
            return p2;
        if(!p2)
            return p1;
        node *temp= new node;
        if(p1->exp==p2->exp){
            temp->exp=p1->exp;
            temp->coe=p1->coe+p2->coe;
            temp->next=addre(p1->next,p2->next);
        }
        else if(p1->exp>p2->exp){
            // node *temp= new node;
            temp->exp=p1->exp;
            temp->coe=p1->coe;
            temp->next=addre(p1->next,p2);
        }
        else{
            // node *temp= new node;
            temp->exp=p2->exp;
            temp->coe=p2->coe;
            temp->next=addre(p1,p2->next);
        }
        return temp;
    }

    
    void disp(){
        node *trav= new node;
        trav=p;
        if(trav->next==NULL){
            if(trav->exp==0)
                cout<<trav->coe<<endl;
            else
                cout<<trav->coe<<"x^"<<trav->exp<<endl;
            return;
        }
        do{
            cout<<trav->coe<<"x^"<<trav->exp<<" + ";
            trav=trav->next;
        }while(trav->next!=NULL);
        cout<<trav->coe;
        cout<<endl;
    }
    int eval(){
        int x,ans=0;
        cout<<"Enter Value of x: ";
        cin>>x;
        while(p!=NULL){
            cout<<ans<<endl;
            ans+=p->coe*(pow(x,p->exp));
            p=p->next;
        }
        return ans;
    }   
    node* multiply(node* pp1,node*pp2){
        int res1,res2;
        node *p1=pp1;
        node *p2=pp2;
        while(p1!=NULL){
            while(p2!=NULL){
                res1=p1->coe*(p2->coe);
                res2=p1->exp+(p2->exp);
                append(res1,res2);
                p2=p2->next;

            }
            p1=p1->next;
            p2=pp2;
            
        }
        return p;

    }
    
   
};

int main(){
    poly p1,p2,ares,mres;
    cout<<"Enter Polynomial 1: "<<endl;
    p1.readpoly();
    cout<<"Enter Polynomial 2: "<<endl;
    p2.readpoly();
    cout<<"\nPolynomial 1: ";p1.disp();cout<<endl;
    cout<<"Polynomial 2: ";p2.disp();cout<<endl;
    // Two add method Recursion(addre) and Iterative(addn)
    ares.p=ares.addn(p1.p,p2.p);
    cout<<"Result after Adding: ";ares.disp();cout<<endl;
    //p3.p=p3.addre(p1.p,p2.p);
    
    
    mres.p=mres.multiply(p1.p,p2.p);
    cout<<"Result after Multiplication: ";mres.disp();cout<<endl;



    
}

