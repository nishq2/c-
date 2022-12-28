#include <iostream>
#define MAX 100
using namespace std;

class que{
    public:
    int f,r;
    int arr[MAX];
    que(){
    f=-1;
    r=-1;
    }
    void enq(int ele){
        if(r==MAX-1){
            cout<<"Queue is full";
            return;
        }
        arr[++r]=ele;
    }
    int deq(){
        if (r==f){
            cout<<"Queue is empty";
            return -999;
        }
        f++;
        return arr[f];
    }
};

class stk{
    que q1,q2;
public:
    void push(int ele){
        q1.enq(ele);
    }
    int pop(){
        while(q1.f!=q1.r-1){
            q2.enq(q1.deq());
        }
        int ele=q1.deq();
        while(q2.f!=q2.r){
            q1.enq(q2.deq());
        }
        return ele;
    }
    void display(){
        if(q1.r==q1.f){
            cout<<"Stack is empty";
            return;
        }
        cout<<"Top"<<endl;
        for(int i=q1.r;i>q1.f;i--){
            cout<<q1.arr[i]<<" ";
        }
    }
};

int main(){
    stk s;
    s.push(45);
    s.push(58);
    s.push(41);
    s.push(89);
    s.push(72);
    s.display();
    cout<<"\n\n"<<s.pop();
return 0;
}
