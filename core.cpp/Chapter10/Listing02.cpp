// Listing 10.2	Example of operator function overloading.

#include <iostream> 
using namespace std;

struct Complex {                                  // programmer-defined type
   double real, imag; } ;

Complex operator+(const Complex &a, const Complex &b)  // magic function name
{ Complex c;                                           // local object
  c.real = a.real + b.real;                       // add real components
  c.imag = a.imag + b.imag;                       // add imaginary components
  return c; }

void operator += (Complex &a, const Complex &b)        // another magic name
{ a.real = a.real + b.real;                       // add to the real component
  a.imag = a.imag + b.imag; }                     // add to the imag component

void operator += (Complex &a, double b)           // different interface
{ a.real += b; }                                  // add to real component only

void showComplex(const Complex &x)
{ cout << "(" << x.real << ", " << x.imag << ")" << endl; }

int main()
{  Complex x, y, z1, z2;                        // objects of type Complex
   x.real = 20; x.imag = 40;                    // initialization
   y.real = 30; y.imag = 50; 
   cout << " First value:  ";  showComplex(x); 
   cout << " Second value: ";  showComplex(y); 
   z1 = operator+(x,y);                         // use in the function call
   cout << " Sum as function call:   "; showComplex(z1); 
   z2 = x + y;                                  // use as the operator
   cout << " Sum as the operator:    "; showComplex(z1); 
   z1 += x;                                     // same as operator+=(z1,x);
   cout << " Add first value to sum: "; showComplex(z1); 
   z2 += 30.0;                                  // same as operator+=(z2,30.0);
   cout << " Add 30 to sum:          "; showComplex(z2); 
   return 0;
  }

