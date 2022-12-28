#include <iostream>
using namespace std;
class Complex{
   float real, imag;
  public:
   void getdata();
   void putdata();
   void sum(Complex A, Complex B);
};
void Complex::getdata(){
  cout<<“Enter real part: ”;
  cin>>real;
  cout<<“enter the imaginary part: ”;
  cin>> imag;
}
void Complex::putdata(){
 if(imag>=0)
     cout<<real<<“+”<<imag<<“i”;
  else
     cout<<real<<imag<<“i”;
}
void Complex::sum(Complex A, Complex B)
{
  real = A.real + B.real;
  imag = A.imag + B.imag;
}
int  main()
{
  Complex x, y, z;
  x.getdata();
  y.getdata();
  z.sum(x, y);
  z.putdata();
  return 0;
}