// Listing 14.4	Example of code reuse through protected inheritance.

#include <iostream> 
using namespace std;

class Circle                 // original code for reuse
{ protected:           // inheritance is one of the options
    double radius;              // internal data
  public:
    static const double PI;     // it must be initialized 

  public:
    Circle (double r)           // conversion constructor
    { radius = r; }

    double getLength () const   // compute circumference
    { return 2 * PI * radius; }

    double getArea () const     // compute area
    { return PI * radius * radius; }

    double getRadius() const
    { return radius; }

    void set(double r)
    { radius = r; } };       // change size

  const double Circle::PI = 3.1415926536;

class Cylinder : protected Circle         // new class Cylinder
{ protected: 
    double height;                 // other data is in Circle

  public:
    Cylinder (double r, double h)  // from Circle plus new code
        : Circle(r)                // initializer list (no PI)
    { height = h; }                // new code

    double getLength () const
    { return Circle::getLength(); }      // from class Circle

    double getRadius() const             // from class Circle
    { return Circle::getRadius(); }

    void set(double r)                   // from class Circle
    { Circle::set(r); } 

    double getVolume() const                  // no getArea()
    { return height * getArea(); } // additional capability
   } ;

int main()
{ 
 Cylinder cyl1(2.5,6.0), cyl2(5.0,7.5);   // initialize data
 double length = cyl1.getLength();        // similar to Circle
 cyl1.set(3.0);
 double diam = 2 * cyl1.getRadius();      // no call to getArea()
 double vol = cyl2.getVolume();           // not in Circle
 cout << " Circumference of first cylinder: " << length << endl;
 cout << " Volume of the second cylinder:   " << vol << endl;
 cout << " Diameter of the first cylinder:  " << diam << endl;
 return 0;
  }

