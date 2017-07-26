// Listing 14.1	Example of code reuse through human intelligence.

#include <iostream> 
using namespace std;

class Cylinder                     // new class Cylinder
{ protected: 
    static const double PI;        // from class Circle
    double radius;                 // from class Circle
    double height;                 // new code

  public:
    Cylinder (double r, double h)  // from Circle plus new code
    { radius = r; 
      height = h; }                // new code

    double getLength () const
    { return 2 * PI * radius; }    // from class Circle

    double getRadius() const       // from class Circle
    { return radius; }

    void set(double r)             // from class Circle
    { radius = r; } 

    double getVolume() const                  // no getArea()
    { return PI * radius * radius * height; } // new code
   } ;

const double Cylinder::PI = 3.1415926536;

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

