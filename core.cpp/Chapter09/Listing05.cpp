// Listing 9.5.	Using a global variable to count object instances.

#include <iostream> 
using namespace std;

int count = 0;                   // does maintainer know it belongs to Point?

class Point { 
     int x, y;                                     // private coordinates
   public:
     Point (int a=0, int b=0)                      // general constructor
       { x = a;  y = b;  count++;
         cout << " Point created: x=" << x << " y=" << y << endl; } 
     void set (int a, int b)                  // modifier function
       { x = a;  y = b; } 
     void get (int& a, int& b) const          // selector function
       { a = x;  b = y; }
     void move (int a, int b)                 // modifier function
       { x += a;  y += b; }
     ~Point()                                    // destructor
       { count--; 
         cout << " Point destroyed: x=" << x << " y=" << y << endl; } 
 } ; 

int quantity()                                 // access to global variable
 { return count; }

int main()
{ cout << "Number of points: " << quantity() << endl;
  Point *p = new Point(80,90);      // dynamically allocated Point object 
  Point p1, p2(30), p3(50,70);      // point of origin, x-axis, general point
  cout << "Number of points: " << quantity() << endl;
  return 0;                         // dynamic object is not properly deleted
  }
