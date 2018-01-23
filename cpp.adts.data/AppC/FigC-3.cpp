/*-------------------------------------------------------------------------
  Program to compute the volumes of spheres of various radii.
  Written at Doofus Univ. by Joe Somebody for CPSC 31416.

  Input:  Radii of spheres
  Output: Volumes of spheres
--------------------------------------------------------------------------*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  const double PI = 3.14159265359;
  double radius;                     // radius of a sphere
  int count = 0;                     // number of spheres processed
  char  response;                    // user response to "More data?"
  do
  {
    cout << "Enter radius of sphere: ";
    cin >> radius;                   // get next radius
    count++;                         //   count the data
                                     //   find the volume
    double volume = 4.0 * PI * pow(radius, 3)/ 3.0;
                                     //   output the results
    cout << "Volume of sphere of radius " << radius
         << " is " << volume << " cubic inches.\n\n";
                                     // query user if more data
    cout << "More data (Y or N)? ";
    cin >> response;
  }
  while (response == 'Y' || response == 'y');

  // Output data count
  cout << endl << count << " spheres processed\n";
}
