// Listing 11.1	Example of passing object parameters by value.

#include <iostream.h> 

class Rational {
  long nmr, dnm;                     // private data
  void normalize();                  // private member function
public:
Rational(long n=0, long d=1)    // general, conversion, default
  { nmr = n;  dnm = d;
    this->normalize(); 
    cout << " created: " << nmr << " " << dnm << endl; }
Rational(const Rational &r)          // copy constructor
  { nmr = r.nmr;  dnm = r.dnm;
    cout << " copied:  " << nmr << " " << dnm << endl; }
void operator = (const Rational &r)  // assignment operator
  { nmr = r.nmr;  dnm = r.dnm;
    cout << " assigned:  " << nmr << " " << dnm << endl; }
~Rational()                          // destructor
  { cout << " destroyed: " << nmr << " " << dnm << endl; }
friend Rational operator + (const Rational x, const Rational y);
void show() const;
  } ;                        // end of class specification

void Rational::show() const
{ cout << " " << nmr << "/" << dnm; }

void Rational::normalize()           // private member function
{ if (nmr == 0) { dnm = 1;  return; }
  int sign = 1;                     
  if (nmr < 0) { sign = -1; nmr = -nmr; }  // make both positive
  if (dnm < 0) { sign = -sign;  dnm = -dnm; }
  long gcd = nmr, value = dnm;  // greatest common divisor
  while (value != gcd) {        // stop when the GCD is found
    if (gcd > value)
      gcd = gcd - value;        // subtract smaller from greater
    else  value = value - gcd; }
  nmr = sign * (nmr/gcd); dnm = dnm/gcd; } // make dnm positive

Rational operator + (const Rational x, const Rational y) 
{ return Rational(y.nmr*x.dnm + x.nmr*y.dnm, y.dnm*x.dnm); } 

int main()
{ Rational  a(1,4), b(3,2), c; 
  cout << endl;
  c = a + b;
  a.show(); cout << " +"; b.show(); cout << " ="; c.show(); 
  cout << endl << endl;
  return 0;
  }

