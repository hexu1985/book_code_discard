// Listing 10.1	Example of operations over objects of class Complex.

#include <iostream> 
using namespace std;

struct Complex {                           // programmer-defined type
   double real, imag; } ;

int main()
{  Complex x, y, z1, z2;                   // objects of type Complex
   x.real = 20; x.imag = 40;               // initialization
   y.real = 30; y.imag = 50; 
   cout << " First value:  ";
   cout << "(" << x.real << ", " << x.imag << ")" << endl; 
   cout << " Second value: ";
   cout << "(" << y.real << ", " << y.imag << ")" << endl; 
   z1.real = x.real + y.real;              // add real components into z1
   z1.imag = x.imag + y.imag;              // add imaginary components
   cout << " Sum of two values:      "; 
   cout << "(" << z1.real << ", " << z1.imag << ")" << endl; 
   z2.real = x.real + y.real;              // add real components into z2
   z2.imag = x.imag + y.imag;              // add imaginary components
   z1.real = z1.real + x.real;             // add to the real component of z1
   z1.imag = z1.imag + x.imag;             // add to the imag component of z1
   cout << " Add first value to z1: ";
   cout << "(" << z1.real << ", " << z1.imag << ")" << endl; 
   z2.real += 30.0;                        // add to real component of z2
   cout << " Add 30 to sum:         ";
   cout << "(" << z2.real << ", " << z2.imag << ")" << endl; 
   return 0;
  }
