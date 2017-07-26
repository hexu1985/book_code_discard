// Listing 10.4	Overloaded operator functions implemented outside the class specification.

#include <iostream> 
using namespace std;

class Complex {                         // programmer-defined data type
   double real, imag;                   // private data
public:                                 // public member functions
  Complex(double r, double i);                 // general constructor
  Complex operator+(const Complex &b) const;   // no change to target
  void operator += (const Complex &b);         // target object changes
  void operator += (double b);                 // target object changes
  void operator + () const;                    // no change to target
} ;                                  // end of class Complex

Complex::Complex(double r, double i)           // general constructor
   { real =r;  imag = i; }

Complex Complex::operator+(const Complex &b) const // no change to target
{ return Complex (real + b.real, imag + b.imag); }

void Complex::operator += (const Complex &b)   // target object changes
{ real = real + b.real;        // add to the real component of the target
  imag = imag + b.imag; }      // add to the imag component of the target

void Complex::operator += (double b)           // target object changes
{ real += b; }                      // add to real component of the target

void Complex::operator + () const              // no change to target
{ cout << "(" << real << ", " << imag << ")" << endl; } // target's fields

int main()
{ Complex x(20,40), y(30,50), z1(0,0), z2(0,0); // defined, initialized
   cout << " Value of x:  ";  +x;               // same as x.operator+();
   cout << " Value of y:  ";  y.operator+();    // anything goes
   z1 = x.operator+(y);                         // use in the function call
   cout << " z1 = x + y:   ";  +z1; 
   z2 = x + y;                                  // same as z2=x.operator+(y);
   cout << " z2 = x + y:   ";  +z2; 
   z1 += x;                                     // same as z1.operator+=(x);
   cout << " Add x to z1:  ";  +z1; 
   z2 += 30.0;                                  // same as z2.operator+=(30.0);
   cout << " Add 30 to z2: ";  +z2;
   return 0;
  }
