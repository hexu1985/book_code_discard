// Listing 10.3	Overloaded operator functions as class members.

#include <iostream> 
using namespace std;

class Complex {                                    // programmer-defined type
   double real, imag;                              // private data
public:                                            // public member functions

Complex(double r, double i)                        // general constructor
   { real =r;  imag = i; }

Complex operator+(const Complex &b)                // one parameter only
{ return Complex (real + b.real, imag + b.imag); } //nice code, fast and neat

void operator += (const Complex &b)        // does target object change?
{ real = real + b.real;        // add to the real component of the target
  imag = imag + b.imag; }      // add to the imag component of the target

void operator += (double b)                // different parameter list
{ real += b; }                 // add to real component of the target

void operator + ()             // it used to be showComplex(const Complex &x)
{ cout << "(" << real << ", " << imag << ")" << endl; } // target's fields
} ;                                                // end of class Complex

int main()
{  Complex x(20,40), y(30,50), z1(0,0), z2(0,0); // defined, initialized
   cout << " Value of x:  ";  +x;          // same as x.operator+();
   cout << " Value of y:  ";  y.operator+();    // anything goes
   z1 = x.operator+(y);                         // use in the function call
   cout << " z1 = x + y:   ";
   +z1;                                    // display z1 
   z2 = x + y;                             // same as z2=x.operator+(y);
   cout << " z2 = x + y:   ";
   +z2;                                    // display z2
   z1 += x;                                // same as z1.operator+=(x);
   cout << " Add x to z1:  ";  +z1; 
   z2 += 30.0;                             // same as z2.operator+=(30.0);
   cout << " Add 30 to z2: ";  +z2; 
   return 0;
  }
