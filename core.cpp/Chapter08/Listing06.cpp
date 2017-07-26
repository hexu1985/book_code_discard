// Listing 8.6.	Example of direct access to underlying data representation

#include <iostream>                 // no encapsulation yet
using namespace std;

struct Cylinder {                   // data structure to access
   double radius, height; } ;

int main()
{ 
  Cylinder c1, c2;                              // program data
  cout << "Enter radius and height of the first cylinder:  ";
  cin >> c1.radius >> c1.height;     // initialize first cylinder
  cout << "Enter radius and height of the second cylinder: ";
  cin >> c2.radius >> c2.height;     // initialize second cylinder
  if (c1.height*c1.radius*c1.radius*3.141593    // compare volumes
     < c2.height*c2.radius*c2.radius*3.141593) 
   { c1.radius *= 1.2;  c1.height *= 1.2;       // scale it up and
     cout << "\nFirst cylinder changed size\n"; // print new size
     cout <<"radius: "<<c1.radius<<" height: "<<c1.height<<endl; } 
  else                                    // otherwise do nothing
     cout << "\nNo change in first cylinder size" << endl;
  return 0;
  }
