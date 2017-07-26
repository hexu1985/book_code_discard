// Listing 15.1	Using pointers to access objects of base and derived classes.

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
   { }                                 // empty constructor body
  void access (int &a, int &b) const   // added in derived class
  { a = Base::x;  b = y; } } ;

int main()
{ 
  int x, y;  
  Derived *pd = new Derived(50,80);    // unnamed derived object
  cout << " 1. Derived pointer, object, and derived method\n";
  pd->access(x,y);                     // no problem: type match
  cout <<" x = " <<x <<"  y = " <<y <<endl <<endl; // x=50 y=80
  cout << " 2. Derived pointer, derived object, base method\n";
  cout << " x = " << pd->show() << endl << endl;   // x = 50
  Base *pb = pd;                       // pointer to same object
  cout << " 3. Base pointer, derived object, base method\n";
  cout << " x = " << pb->show() << endl << endl;   // x = 50
//  pb->access(x,y);       // error: no access to derived method
  cout << " 4. Converted pointer, derived object and method\n";
  ((Derived*)pb)->access(x,y);         // we know it is there
  cout <<" x = " <<x <<"  y = " <<y <<endl <<endl; // x=50 y=80
  pb = new Base(60);                   // unnamed base object
  cout << " 5. Base pointer, base object, base method\n";
  cout << " x = " << pb->show() << endl <<endl;    // x = 60
  cout << " 6. Converted pointer, base object, derived method\n";
  ((Derived*)pb)->access(x,y);         // pass on your own risk
  cout <<" x = " <<x <<"  y = " <<y <<endl <<endl;  // junk!!
  delete pd;  delete pb;               // necessary tidiness
  return 0;
  }
