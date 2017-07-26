// Listing 15.2	Passing pointer and reference arguments of base and derived classes.

#include <iostream> 
using namespace std;

class Base {                           // base class
protected:
   int x;
public:
  Base(int a)                          // to be used by Derived
  { x = a; } 
  void set (int a)                     // to be inherited 
  { x = a; }
  int show () const                    // to be inherited
  { return x; } } ;

class Derived : public Base {          // derived class
   int y;
public:
  Derived (int a, int b) : Base(a), y(b)
    { }                                // empty constructor body
  Derived(const Base &b) : Base(b)     // supports implicit cast
  { y = 0; }                           // explicit initialization
  void access (int &a, int &b) const   // added in derived class
  { a = Base::x;  b = y; } } ;

class Other {                          // another class
   int z;
public:
   void setB(const Base &b)            // pass by reference
   { z = b.show(); }
   void setB(const Base *b)            // pass by pointer
   { z = b->show(); } 
   void setD(const Derived &d)         // pass by reference
   { int a; d.access(a,z); }
   void setD(const Derived *d)         // pass by pointer
   { int a; d->access(a,z); }
   int get() const                     // accessor
   { return z; }
} ;

int main()
{ 
  Base b(30);  Derived d(50,80);       // related objects
  Other a1, a2;                        // unrelated object
  a1.setB(b);  a2.setD(d);             // exact match
  cout << " a1=" << a1.get() << "  a2=" << a2.get() << endl;
  a1.setB(d);  a2.setD(b);             // implicit conversions
  cout << " a1=" << a1.get() << "  a2=" << a2.get() << endl;
  a1.setB(&b);  a2.setD(&d);           // exact match
  cout << " a1=" << a1.get() << "  a2=" << a2.get() << endl;
  a1.setB(&d);                         // implicit conversion
  // a2.setD(&b);                      // syntax error
  a2.setD((Derived*)&b);               // explicit conversion
  cout << " a1=" << a1.get() << "  a2=" << a2.get() << endl;
  return 0;
  }
