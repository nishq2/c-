#include <iostream>
using namespace std;
#define MAX 100
class y{
    int b[MAX];
    int top[MAX];
    int a[MAX];
    public:
    y(int n){
        for(int i=0;i<n;i++){
            b[i] = top[i] = (MAX-1/n)*i-1;
        }
    }
    void push(int i, int x){
        if((top[i] == b[i+1]) || (top[i] == MAX-1)){
            cout<<"Stack is full";
            return;
        }
        a[++top[i]] = x;
    }
    void pop(int i){
        if(top[i] == b[i]){
            cout<<"Stack is empty";
            return;
        }
        cout<<a[top[i]--];
    }
};
int main(){
    int n;
    cout<<"Enter the number of STACKS to be created: ";
    cin>>n;
    y s1;
    s1.push(1,23);
    s1.push(2,12);
    s1.push(3,31);
    s1.pop(1);
}