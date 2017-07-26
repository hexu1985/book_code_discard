// Listing 5.12. Using #include directive for programmer-defined types

#include <iostream>  
#include <cmath>           // to support sqrt() and atan2()
#include "point.h"         // to make type Point known to compiler
#include "line.h"          // to make type Line known to compiler
using namespace std;

int main ()
{ 
  const double coeff = 180/3.1415926536;
  Point p1, p2;  Line line1, line2;    // programmer-defined types
  int diffX, diffY, length1, length2;
  double angle1, angle2;
  cout << "Enter x and y coordinates of point A: ";
  cin >> p1.x >> p1.y;
  cout << "Enter x and y coordinates of point B: ";
  cin >> p2.x >> p2.y;
  line1.start = p1;  line1.end = p2;
  cout << "Enter x and y coordinates of point C: ";
  cin >> p1.x >> p1.y;
  cout << "Enter x and y coordinates of point D: ";
  cin >> p2.x >> p2.y;
  line2.start = p1;  line2.end = p2;
  diffX = line1.end.x - line1.start.x;           // ugly notation
  diffY = line1.end.y - line1.start.y;
  length1 = sqrt(diffX*diffX + diffY*diffY) + 0.5; // conversions
  angle1 = atan2(diffY,diffX) * coeff;
  cout << "Length AB is " << length1 << " at angle " 
       << angle1 << " degrees\n";
  diffX = line2.end.x - line2.start.x;  
  diffY = line2.end.y - line2.start.y;
  length2 = sqrt(diffX*diffX + diffY*diffY) + 0.5; // conversions
  angle2 = atan2(diffY,diffX) * coeff;
  cout << "Length CD is " << length2 << " at angle " 
       << angle2 << " degrees\n";
  return 0;
  }
