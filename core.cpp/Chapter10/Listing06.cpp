// Listing 10.6	Class Rational that supports mixed types in expressions.

#include <iostream> 
using namespace std;

class Rational {
  long nmr, dnm;                          // private data
  void normalize();                       // private member function
public:
  Rational(long n=0, long d=1)  // general, conversion, default constructor
  { nmr = n;  dnm = d;
    this->normalize(); }
Rational operator + (const Rational &x) const;    // constant target
Rational operator - (const Rational &x) const;
Rational operator * (const Rational &x) const;
Rational operator / (const Rational &x) const;
  void operator += (const Rational &x);           // target changes
  void operator -= (const Rational &x);
  void operator *= (const Rational &x); 
  void operator /= (const Rational &x);
bool operator == (const Rational &other) const;   // constant target
bool operator < (const Rational &other) const;
bool operator > (const Rational &other) const;
void show() const;
  } ;                          // end of class specification

Rational Rational::operator + (const Rational &x) const
{ return Rational(nmr*x.dnm + x.nmr*dnm, dnm*x.dnm); } // e.g., 1/4+3/2=14/8

Rational Rational::operator - (const Rational &x) const
{ return Rational(nmr*x.dnm - x.nmr*dnm, dnm*x.dnm); } // e.g., 3/2-1/4=10/8

Rational Rational::operator * (const Rational &x) const
{ return Rational(nmr * x.nmr, dnm * x.dnm); }

Rational Rational::operator / (const Rational &x) const
{ return Rational(nmr * x.dnm, dnm * x.nmr); }

void Rational::operator += (const Rational &x)
{ nmr = nmr * x.dnm + x.nmr * dnm; // 3/8+3/2=(6+24)/16=15/8
  dnm = dnm * x.dnm; // n1/d1+n2/d2 = (n1*d2+n2*d1)/(d1*d2)
  this->normalize(); }

void Rational::operator -= (const Rational &x)
{ nmr = nmr * x.dnm - x.nmr * dnm; // 3/8+3/2=(6+24)/16=15/8
  dnm = dnm * x.dnm; // n1/d1+n2/d2 = (n1*d2-n2*d1)/(d1*d2)
  this->normalize(); }

void Rational::operator *= (const Rational &x)
{ nmr = nmr * x.nmr;  dnm =  dnm * x.dnm; 
  this->normalize(); }

void Rational::operator /= (const Rational &x)
{ nmr = nmr * x.dnm;  dnm =  dnm * x.nmr; 
  this->normalize(); }

bool Rational::operator == (const Rational &other) const
{ return (nmr * other.dnm == dnm * other.nmr); }

bool Rational::operator < (const Rational &other) const
{ return (nmr * other.dnm < dnm * other.nmr); }

bool Rational::operator > (const Rational &other) const
{ return (nmr * other.dnm > dnm * other.nmr); }

void Rational::show() const
{ cout << " " << nmr << "/" << dnm; }

void Rational::normalize()                        // private member function
{ if (nmr == 0) { dnm = 1;  return; }
  int sign = 1;                     
  if (nmr < 0) { sign = -1; nmr = -nmr; } 
  if (dnm < 0) { sign = -sign;  dnm = -dnm; }
  long gcd = nmr, value = dnm;   // start looking for greatest common divisor
  while (value != gcd) {         // stop when the GCD is found
    if (gcd > value)
      gcd = gcd - value;         // subtract smaller number from the greater
    else  value = value - gcd; }
  nmr = sign * (nmr/gcd); dnm = dnm/gcd; } // denominator is always positive

int main()
{ cout  << endl << endl;
  Rational  a(1,4), b(3,2), c, d;
  c = a + 5;                               // I'll discuss c = 5 + a; later
  a.show(); cout << " + " << 5 << " ="; c.show(); cout << endl;
  d = b - 1;
  b.show(); cout << " - " << 1 << " ="; d.show(); cout << endl;
  c = a * 7;
  a.show(); cout << " * " << 7 << " ="; c.show(); cout << endl;
  d = b / 2;
  b.show(); cout << " / " << 2 << " ="; d.show(); cout << endl;
  c.show();
  c += 3;
  cout << " += " << 3 << " ="; c.show(); cout << endl;
  d.show();
  d *= 2;
  cout << " *= " << 2 << " ="; d.show(); cout << endl;
  if (b < 2)
  { b.show(); cout << " < " << 2 << endl; }
  return 0;
  }
