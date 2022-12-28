#include <iostream>
#include <math.h>
using namespace std;
class node
{
public:
    int exp, coe;
    node *next;
};

class poly
{

public:
    node *p;
    poly()
    {
        p = NULL;
    }
    void append(int c, int e)
    {
        if (c == 0)
        {
            return;
        }
        node *temp = new node;
        temp->coe = c;
        temp->exp = e;
        temp->next = NULL;
        node *t = p;
        if (p == NULL)
        {
            p = temp;
            return;
        }

        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
    void delete1(node *p1)
    {
        if (p1->coe == 0)
        {
            node *t = p1;
            p1 = t->next;
            delete t;
            return;
        }
    }

    void readpoly()
    {
        while (1)
        {
            int coe, exp;
            cout << "Enter Coefficient and Exponent: ";
            cin >> coe >> exp;
            if (coe == -999)
            {
                break;
            }
            append(coe, exp);
        }
    }

    node *addn(node *pp1, node *pp2)
    {
        node *p1 = pp1;
        node *p2 = pp2;
        int s, c;
        if (p1 == NULL)
            return p2;
        if (p2 == NULL)
            return p1;
        while (p1 != NULL && p2 != NULL)
        {   c=0;
            if (p1->exp == p2->exp)
                s = 0;
            else if (p1->exp > p2->exp)
                s = 1;
            else
                s = -1;
            switch (s)
            {
            case 0:
            
                c = p1->coe + p2->coe;
                append(c, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
                break;
            case 1:
                append(p1->coe, p1->exp);
                p1 = p1->next;
                break;
            default:
                append(p2->coe, p2->exp);
                p2 = p2->next;
                break;
            }
        }
        
        while (p1!= NULL)
        {
            append(p1->coe, p1->exp);
            
            p1 = p1->next;
            
        }
        while (p2 != NULL)
        {   
            append(p2->coe, p2->exp);
            p2 = p2->next;
        }
        //cout << p1->coe << " " << p1->exp;
        

        return p;
    }
    node *sub( node *p2)
    {           
        node *t = p2;

        while (t != NULL)
        {
            t->coe = (-1) * t->coe;
            
            t = t->next;
        }
        
        return p2;
    }
    // using recursion
    node *addre(node *p1, node *p2)
    {
        if (!p1)
            return p2;
        if (!p2)
            return p1;
        node *temp = new node;
        if (p1->exp == p2->exp)
        {
            temp->exp = p1->exp;
            temp->coe = p1->coe + p2->coe;
            temp->next = addre(p1->next, p2->next);
        }
        else if (p1->exp > p2->exp)
        {
            // node *temp= new node;
            temp->exp = p1->exp;
            temp->coe = p1->coe;
            temp->next = addre(p1->next, p2);
        }
        else
        {
            // node *temp= new node;
            temp->exp = p2->exp;
            temp->coe = p2->coe;
            temp->next = addre(p1, p2->next);
        }

        return temp;
    }

    void disp()
    {
        node *trav;
        trav = p;
        if (trav->next == NULL)
        {
            if (trav->exp == 0)
                cout << trav->coe << endl;
            else
                cout << trav->coe << "x^" << trav->exp << endl;
            return;
        }
        do
        {
            cout << trav->coe << "x^" << trav->exp << " + ";
            trav = trav->next;
        } while (trav->next != NULL);
        if (trav->exp == 0)
            cout << trav->coe << endl;
        else
            cout << trav->coe << "x^" << trav->exp << endl;

        cout << endl;
    }
    int eval()
    {
        int x, ans = 0;
        cout << "Enter Value of x: ";
        cin >> x;
        while (p != NULL)
        {
            cout << ans << endl;
            ans += p->coe * (pow(x, p->exp));
            p = p->next;
        }
        return ans;
    }
    node *multiply(node *pp1, node *pp2)
    {
        int res1, res2;
        node *p1 = pp1;
        node *p2 = pp2;
        while (p1 != NULL)
        {
            p2 = pp2;
            while (p2 != NULL)
            {
                res1 = p1->coe * (p2->coe);
                res2 = p1->exp + (p2->exp);
                append(res1, res2);
                p2 = p2->next;
            }
            p1 = p1->next;
        }
        return p;
    }
    

    void divide(node *p1, node *p2)
    {

        poly q, r;
        poly z1,z2,z3,z4,z5,z6;
        
        r.p = p1;
        int c, e;
        int i=0;
        
        while (1)
        {  while(r.p->next!=NULL){
            
            if(r.p==NULL){
              
                break;
            }
            else if(r.p->coe!=0){
               
                break;
                
            }
            
            r.p=r.p->next;
        }
            if((r.p->exp)<(p2->exp)){
             
                break;
                
            }
        
            
            e = (r.p->exp) - (p2->exp);
            c = (r.p->coe) / (p2->coe);
            q.append(c, e);
            
            
            node *N=new node;
            N->coe=c;
            N->exp=e;
            N->next=NULL;
            poly s;
            s.p=NULL;
            s.p = s.multiply(p2, N);
            
            if(i==0){
                z1.p=sub(s.p);
                z1.p=addn(r.p,s.p);
               
                r.p=z1.p;
            }
            if(i==1){
                z2.p=sub(s.p);
          
                z2.p=addre(r.p,z2.p);
               
                r.p=z2.p;
            }
            if(i==2){
                z3.p=sub(s.p);
                z3.p=addre(r.p,z3.p);
                r.p=z3.p;
            }
            i++;
            r.disp();
           q.disp();
        }

        cout << "Displaying Quotient: ";
        q.disp();cout<<endl;
        cout << "Displaying Remainder: ";
        r.disp();cout<<endl;
        // 4 2 6 1 2 0 -999 9 2 1 1 0 -999 9
    }
};

int main()
{
    poly p1, p2, ares, sres, mres, dres;
    cout << "Enter Polynomial 1: " << endl;
    p1.readpoly();
    cout << "Enter Polynomial 2: " << endl;
    p2.readpoly();
    cout << "\nPolynomial 1: ";
    p1.disp();
    cout << endl;
    cout << "Polynomial 2: ";
    p2.disp();
    cout << endl;
    // // Two add method Recursion(addre) and Iterative(addn)
    // ares.p=ares.addn(p1.p,p2.p);
    // //p3.p=p3.addre(p1.p,p2.p);
    // cout<<"Result after Adding: ";ares.disp();cout<<endl;
    // sres.p=sres.sub(p1.p,p2.p);
    // cout<<"Result after Subtraction: ";sres.disp();cout<<endl;
    // mres.p=mres.multiply(p1.p,p2.p);
    // cout<<"Result after Multiplication: ";mres.disp();cout<<endl;

    dres.divide(p1.p, p2.p);
}
