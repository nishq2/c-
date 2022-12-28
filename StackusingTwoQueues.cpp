#include <iostream>
using namespace std;

 int const MAX = 100;

class int_stak{

    int arr[MAX];
    int top;

public:

    //  FUNCTION TO INITIALISE THE CLASS OBJECT
    int_stak()
    {
        top = -1;
    }

    int peek()
        {
            if(top == -1)
                return 65536;
            return arr[top];
        }
    //  FUNCTION TO POP AN ELEMENT AND RETURN IT
    int pop()
    {
        if(top == -1)
        {
            cout<<"Underflow Detecteded"<<endl;
            return 65536;
        }
        return arr[top--];

    }

    void push(int k)
    {
        if(top == MAX - 1)
        {
            cout<<"Overflow Detexted"<<endl;
            return;
        }
        arr[++top] = k;

    }

    //  FUNCTION TO DISPLAY ALL THE ELEMENTS IN THE STACK
    void display()
    {
        if(top == -1)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        for(int i = 0; i<=top; i++)
            cout<<arr[i]<<" ";
    }
};


class stack_as_queue{

    int_stak que;

public:
    void enqueue(int k){
        que.push(k);
    }

    void display(){
        que.display();
        cout<<endl;
    }

    int dequeue(){
        int_stak temp;
        while(que.peek() != 65536)
            temp.push ( que.pop() );
        int returner = temp.pop();
        while(temp.peek() != 65536)
            que.push ( temp.pop() );
        return returner;
    }


};

int main()
{

 stack_as_queue q;
 cout<<endl<<"Enter Options \n 0. To Exit \n 1. To Enqueue and Display \n 2. To Dequeue and Display \n [THE QUEUE SIZE IS "<<MAX<<"]\n";
 do{
    cout<<endl<<"Enter Option    ";
    int key; cin>>key;
    if(key ==0) break;
    if(key ==1) {cout<<"Enter integer to enqueue  "; int temp; cin>>temp; q.enqueue(temp);q.display();}
    if(key ==2) { q.dequeue(); q.display();}

 }while(1);
    return 0;
}
