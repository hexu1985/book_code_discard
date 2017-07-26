// Listing 8.9.	Combining encapsulation and information hiding

#include <iostream>               
using namespace std;

struct Cylinder {          // data structure to access
   double radius, height; } ;

void enterData(Cylinder &c, char number[])
{ cout << "Enter radius and height of the ";
  cout << number << " cylinder:  "; 
  cin >> c.radius >> c.height;           // initialize cylinder
  if (c.radius < 0) c.radius = 10;       // defaults for corrupted data
  if (c.height < 0) c.height = 20; }

bool firstIsSmaller(const Cylinder& c1, const Cylinder& c2)
{ if (c1.height*c1.radius*c1.radius*3.141593  // compare volumes
     < c2.height*c2.radius*c2.radius*3.141593) 
    return true;
  else
    return false; }

void scaleCylinder(Cylinder &c, double factor) 
{ c.radius *= factor;  c.height *= factor; } // scale dimensions

void printCylinder(const Cylinder &c)        // print object state
{ cout << "radius: " <<c.radius << " height: " <<c.height <<endl; }

int main()           // pushing responsibility to server functions
{ 
  Cylinder c1, c2;                               // program data
  enterData(c1,"first");             // initialize first cylinder
  enterData(c2,"second");            // initialize second cylinder
  if (firstIsSmaller(c1,c2))
   { scaleCylinder(c1,1.2);                     // scale it up and
     cout << "\nFirst cylinder changed size\n"; // print new size
     printCylinder(c1); }                       
  else                              // otherwise do nothing
     cout << "\nNo change in first cylinder size" << endl;
  return 0;
  }

