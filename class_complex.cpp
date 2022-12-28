#include <iostream>
using namespace std;
class Complex{
    int a;
    int b;
    public: 
    void Data()
    {
        //int a,b;
        cout<<"enter a no: real part"<<endl;
        cin>>a;
        cout<<"enter a no: imaginary part"<<endl;
        cin>>b;
        //a=v1;
        //b=v2;
    }

void Sum(Complex s1, Complex s2)
{
   //int sum=0;
   cout<<"sum is: "<<(s1.a+s2.a)<<"+"<<(s1.b+s2.b)<<"i"<<endl; 
}
void printno() {
    cout<<"complex no is: "<<a<<"+"<<b<<"i"<<endl;
    
}
};
int main()
{
    Complex c1,c2;
    c1.Data();
    c2.Data();
    c1.printno();
    c2.printno();
    c1.Sum(c1, c2);
    //c3.printno();
    return 0;
}