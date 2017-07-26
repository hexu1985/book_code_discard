// Listing 12.3	Using static data members and a static member function.

#include <iostream> 
using namespace std;


class Point { 
     int x, y;                           // private coordinates
     static int count;
     static Point origin;
   public:
     Point (int a=0, int b=0)            // general constructor
       { x = a;  y = b;  count++;
         cout << " Created: x=" << x << " y=" << y 
              << " count=" << count << endl; } 
     static int quantity()               // const is not allowed 
	 { return count; }  
     void set (int a, int b)             // modifier function
       { x = a;  y = b; } 
     void get (int& a, int& b) const     // selector function
       { a = x;  b = y; }
     void move (int a, int b)            // modifier function
       { x += a;  y += b; }
   ~Point()                            // destructor
     { count--; 
       cout <<" Point destroyed: x=" <<x <<" y=" <<y <<endl; } 
 } ; 

int Point::count = 0;                    // initialization
Point Point::origin(640,0);              // initialization

int main()
{ cout << " Number of points: " << Point::quantity() << endl;
  Point p1, p2(30), p3(50,70); // point of origin, point objects
  cout << " Number of points: " << p1.quantity() << endl;
  return 0;
  }

