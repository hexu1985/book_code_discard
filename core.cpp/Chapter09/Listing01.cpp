// Listing 9.1.	Example of using access function on behalf of the client code.

#include <iostream> 
using namespace std;

struct Cylinder {                   // data structure to access
   double radius, height; } ;

void setCylinder(Cylinder& c, double r, double h)
{ c.radius = r;  c.height = h; }
   
double getVolume(const Cylinder& c)      // compute volume
{ return c.height * c.radius * c.radius * 3.141593; }

void scaleCylinder(Cylinder &c, double factor) 
{ c.radius *= factor;  c.height *= factor; } // scale dimensions

void printCylinder(const Cylinder &c)        // print object state
{ cout << "radius: " <<c.radius << " height: " <<c.height <<endl; }

int main()           // pushing responsibility to server functions
{ Cylinder c1, c2;                               // program data
  setCylinder(c1,10,30); setCylinder(c2,20,30);  // set cylinders
  cout << "\nInitial size of first cylinder\n";
  printCylinder(c1);
  if (getVolume(c1) < getVolume(c2))            // compare volumes
   { scaleCylinder(c1,1.2);                     // scale it up and
     cout << "\nFirst cylinder changed size\n"; // print new size
     printCylinder(c1); }                       
  else                              // otherwise do nothing
     cout << "\nNo change in first cylinder size" << endl;
  return 0;
  }
