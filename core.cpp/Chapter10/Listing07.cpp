// Listing 10.7	Class Rational that uses friend functions to support mixed type expressions.

#include <iostream.h> 

class Rational {
  long nmr, dnm;                          // private data
  void normalize();                       // private member function
public:
Rational(long n=0, long d=1)  // general, conversion, default constructor
  { nmr = n;  dnm = d;
    this->normalize(); }
friend Rational operator + (const Rational &x, const Rational &y);
friend Rational operator - (const Rational &x, const Rational &y);
friend Rational operator * (const Rational &x, const Rational &y);
friend Rational operator / (const Rational &x, const Rational &y);
  friend void operator += (Rational &x, const Rational &y);
  friend void operator -= (Rational &x, const Rational &y);
  friend void operator *= (Rational &x, const Rational &y);
  friend void operator /= (Rational &x, const Rational &y);
friend bool operator == (const Rational &x, const Rational &y);
friend bool operator < (const Rational &x, const Rational &y);
friend bool operator > (const Rational &x, const Rational &y);
void show() const;
  } ;                                     // end of class specification

void Rational::show() const
{ cout << " " << nmr << "/" << dnm; }

void Rational::normalize()                          // private member function
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

Rational operator + (const Rational &x, const Rational &y) 
{ return Rational(y.nmr*x.dnm + x.nmr*y.dnm, y.dnm*x.dnm); }

Rational operator - (const Rational &x, const Rational &y) 
{ return Rational(x.nmr*y.dnm - y.nmr*x.dnm, x.dnm*y.dnm); }

Rational operator * (const Rational &x, const Rational &y) 
{ return Rational(x.nmr * y.nmr, x.dnm * y.dnm); }

Rational operator / (const Rational &x, const Rational &y) 
{ return Rational(x.nmr * y.dnm, x.dnm * y.nmr); }

void operator += (Rational &x, const Rational &y)
{ x.nmr = x.nmr * y.dnm + y.nmr * x.dnm;  x.dnm *= y.dnm;
  x.normalize(); }

void operator -= (Rational &x, const Rational &y)
{ x.nmr = x.nmr*y.dnm + y.nmr*x.dnm; x.dnm *= y.dnm;
  x.normalize(); }

void operator *= (Rational &x, const Rational &y)
{ x.nmr *= y.nmr;  x.dnm *= y.dnm; 
  x.normalize(); }

void operator /= (Rational &x, const Rational &y)
{ x.nmr = x.nmr * y.dnm;  x.dnm =  x.dnm * y.nmr; 
  x.normalize(); }

bool operator == (const Rational &x, const Rational &y)
{ return (x.nmr * y.dnm == x.dnm * y.nmr); }

bool operator < (const Rational &x, const Rational &y)
{ return (x.nmr * y.dnm < x.dnm * y.nmr); }

bool operator > (const Rational &x, const Rational &y)
{ return (x.nmr * y.dnm > x.dnm * y.nmr); }

int main()
{ Rational  a(1,4), b(3,2), c, d;
  c = 5 + a;
  cout << " " << 5 << " +"; a.show(); cout << " ="; c.show(); cout << endl;
  d = 1 - b;                           // operator-(Rational(1),b);
  cout << " 1 -"; b.show(); cout << " ="; d.show(); cout << endl;
  c = 7 * a;                           // operator*(Rational(7),a);
  cout << " 7 *"; a.show(); cout << " ="; c.show(); cout << endl;
  d = 2 / b;                           // operator/(Rational(2),b);
  cout << " 2 /"; b.show(); cout << " ="; d.show(); cout << endl;
  c.show();
  c += 3;                              // operator+=(c,Rational(3));
  cout << " += " << 3 << " ="; c.show(); cout << endl;
  d.show();
  d *= 2;                              // operator*=(d,Rational(2))
  cout << " *= " << 2 << " ="; d.show(); cout << endl;
  if (a < 5) cout << " a < 5\n";       // operator<(a,Rational(5));
  if (1 < b) cout << " 1 < b\n";       // operator<(Rational(1),b);
  if (1 < 5) cout << " 1 < 5\n";       // built-in inequality operator
  if (d * b - a == c - 1) cout << " d*b-a == c-1 =="; 
  (c - 1).show();  cout << endl;
  return 0;
  }
