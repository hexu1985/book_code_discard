// Listing 10.5	Class Rational and its test driver.

#include <iostream> 
using namespace std;

class Rational {
  long nmr, dnm;                                  // private data
  void normalize();                               // private member function
public:
  Rational()                  // default constructor: zero values
  { nmr = 0;  dnm = 1; }
  Rational(long n, long d)    // general constructor: fraction as n/d
  { nmr = n;  dnm = d;
    this->normalize(); }
Rational operator + (const Rational &x) const;    // constant target
Rational operator - (const Rational &x) const;
Rational operator * (const Rational &x) const;
Rational operator / (const Rational &x) const;
  void operator += (const Rational &x);           // target changes
  void operator -= (const Rational&);
  void operator *= (const Rational&); 
  void operator /= (const Rational&); 
bool operator == (const Rational &other) const;   // constant target
bool operator < (const Rational &other) const;
bool operator > (const Rational &other) const;
void show() const;
  } ;                                           // end of class specification

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

void Rational::normalize()                       // private member function
{ if (nmr == 0) { dnm = 1;  return; }
  int sign = 1;                     
  if (nmr < 0) { sign = -1; nmr = -nmr; }  // just for illustration
  if (dnm < 0) { sign = -sign;  dnm = -dnm; }
  long gcd = nmr, value = dnm;   // start looking for greatest common divisor
  while (value != gcd) {         // stop when the GCD is found
    if (gcd > value)
      gcd = gcd - value;         // subtract smaller number from the greater
    else  value = value - gcd; }
  nmr = sign * (nmr/gcd); dnm = dnm/gcd; } // denominator is always positive

void Rational::show() const
{ cout << " " << nmr << "/" << dnm; }

int main()
{ Rational  a(1,4), b(3,2), c, d;
  c = a + b;           // c.nmr is 7, c.dnm is 4
  a.show(); cout << " +"; b.show(); cout << " ="; c.show(); cout << endl;
  d = b - a;
  b.show(); cout << " -"; a.show(); cout << " ="; d.show(); cout << endl;
  c = a * b;           // c.nmr is 3, c.dnm is 8
  a.show(); cout << " *"; b.show(); cout << " ="; c.show(); cout << endl;
  d = b / a;
  b.show(); cout << " /"; a.show(); cout << " ="; d.show(); cout << endl;
  c.show();
  c += b;
  cout << " +="; b.show(); cout << " ="; c.show(); cout << endl;
  d.show();
  d *= b;
  cout << " *="; b.show(); cout << " ="; d.show(); cout << endl;
  if (b < c)
  { b.show(); cout << " <"; c.show(); cout << endl; }
  return 0;
  }
