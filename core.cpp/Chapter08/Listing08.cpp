// Listing 8.8.	Example of ineffective encapsulation

#include <iostream>               // awkward encapsulation 
using namespace std;

struct Cylinder {          // data structure to access
   double radius, height; } ;

void setRadius(Cylinder &c, double r)           // modifier
{ c.radius = r; }

void setHeight(Cylinder &c, double h)           // modifier
{ c.height = h; }

double getRadius(const Cylinder& c)             // accessor
{ return c.radius; }

double getHeight(const Cylinder& c)             // accessor
{ return c.height; }

int main()
{ 
  Cylinder c1, c2;  double radius, height;       // program data
  cout << "Enter radius and height of the first cylinder:  ";
  cin >> radius >> height;                    // initialize data
  setRadius(c1,radius); setHeight(c1,height);
  if (getRadius(c1)<0) setRadius(c1,10);          // verify data
  if (getHeight(c1)<0) setHeight(c1,20);
  cout << "Enter radius and height of the second cylinder: ";
  cin >> radius >> height;                    // initialize data
  setRadius(c2,radius); setHeight(c2,height);
  if (getRadius(c2)<0) setRadius(c2,10);         // verify data
  if (getHeight(c2)<0) setHeight(c2,20);
  if (getHeight(c1)*getRadius(c1)*getRadius(c1)*3.141593
     < getHeight(c2)*getRadius(c2)*getRadius(c2)*3.141593)
   { setRadius(c1,getRadius(c1)*1.2);  
     setHeight(c1,getHeight(c1)*1.2);            // scale up
     cout << "\nFirst cylinder changed size\n"; // print new size
     cout <<"radius: "<<c1.radius<<" height: "<<c1.height<<endl; } 
  else                                    // otherwise do nothing
     cout << "No change in first cylinder size" << endl;
  return 0;
  }
