// Listing 9.6	Using static data members and member functions.

#include <iostream> 
using namespace std;

class Point { 
     int x, y;                                     // private coordinates
     static int count;
   public:
     Point (int a=0, int b=0)                      // general constructor
       { x = a;  y = b;  count++;
         cout << " Point created: x=" << x << " y=" << y << endl; } 
     static int quantity()                    // const is not allowed 
	 { return count; }  
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

int Point::count = 0;

int main()
{ cout << " Number of points: " << Point::quantity() << endl;
  Point p1, p2(30), p3(50,70);      // point of origin, x-axis, general point
  cout << " Number of points: " << p1.quantity() << endl;
  return 0;
  }

