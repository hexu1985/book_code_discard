// Listing 8.7.	Example of using access functions to insulate client code from the names of data fields

#include <iostream>         // encapsulation with server functions
using namespace std;

struct Cylinder {                   // data structure to access
   double radius, height; } ;

void enterData(Cylinder &c, char number[])
{ cout << "Enter radius and height of the ";
  cout << number << " cylinder:  "; 
  cin >> c.radius >> c.height; }      // initialize cylinder

void validateCylinder(Cylinder c)
{ if (c.radius < 0) c.radius = 10;  // defaults for corrupted data
  if (c.height < 0) c.height = 20; }

double getVolume(const Cylinder& c)      // compute volume
{ return c.height * c.radius * c.radius * 3.141593; }

void scaleCylinder(Cylinder &c, double factor) 
{ c.radius *= factor;  c.height *= factor; } // scale dimensions

void printCylinder(const Cylinder &c)        // print object state
{ cout << "radius: " <<c.radius << " height: " <<c.height <<endl; }

int main()           // pushing responsibility to server functions
{ 
  Cylinder c1, c2;                               // program data
  enterData(c1,"first");             // initialize first cylinder
  validateCylinder(c1);              // defaults for corrupted data
  enterData(c2,"second");            // initialize second cylinder
  validateCylinder(c2);              // defaults for corrupted data
  if (getVolume(c1) < getVolume(c2))            // compare volumes
   { scaleCylinder(c1,1.2);                     // scale it up and
     cout << "\nFirst cylinder changed size\n"; // print new size
     printCylinder(c1); }                       
  else                              // otherwise do nothing
     cout << "No change in first cylinder size" << endl;
  return 0;
 }
