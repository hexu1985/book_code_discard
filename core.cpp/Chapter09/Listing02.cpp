// Listing 9.2.	Example of binding data and functions in a class with its own scope.

#include <iostream> 
using namespace std;

struct Cylinder {                      // start of the class scope
   double radius, height;              // data fields to access

void setCylinder(double r, double h)   // set cylinder data
{ radius = r;  height = h; }

double getVolume()                     // compute volume
{ return height * radius * radius * 3.141593; }

void scaleCylinder(double factor)      // scale dimensions
{ radius *= factor;  height *= factor; }

void printCylinder()                   // print object state
{ cout << "radius: " <<radius << " height: " <<height <<endl; }
} ;                                    // end of class scope

int main()              // pushing responsibility to server functions
{ Cylinder c1, c2;                             // define program data
  c1.setCylinder(10,30); c2.setCylinder(20,30); // set cylinders
  cout << "\nInitial size of first cylinder\n";
  c1.printCylinder();
  if (c1.getVolume() < c2.getVolume())          // compare volumes
   { c1.scaleCylinder(1.2);                     // scale it up and
     cout << "\nFirst cylinder changed size\n"; // print new size
     c1.printCylinder(); }                       
   else                                // otherwise do nothing
     cout << "\nNo change in first cylinder size" << endl;
  return 0;
  }
