// Listing 14.5	Example of code reuse through public inheritance 
// with method redefinition.

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
    { radius = r; } };          // change size

  const double Circle::PI = 3.1415926536;

class Cylinder : public Circle  // is Cylinder really a Circle?
 { protected: 
     double height;                 // other data is in Circle
 
   public:
     Cylinder (double r, double h)  // from Circle plus new code
         : Circle(r)                // initializer list (no PI)
     { height = h; }                // new code
 
     double getArea () const         // compute Cylinder area
     { return 2 * Circle::PI * radius * (radius + height); }

     double getVolume() const                       { return height * getArea(); } // additional capability
    } ;
 
 int main()
 { 
  Cylinder cyl1(2.5,6.0), cyl2(5.0,7.5);   // initialize data
  double length = cyl1.getLength();        // similar to Circle
  cyl1.set(3.0);
  double diam = 2 * cyl1.getRadius();double vol = cyl2.getVolume();           // not in Circle
  cout << " Circumference of first cylinder: " << length << endl;
  cout << " Volume of the second cylinder:   " << vol << endl;
  cout << " Diameter of the first cylinder:  " << diam << endl;
  cout << " Area of first cylinder: " << cyl1.getArea() << endl;
  return 0;
  }

