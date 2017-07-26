// Listing 12.2.	Creating a composite object without wasted constructor calls.

#include <iostream> 
using namespace std;

class Point { 
   private:     
     int x, y;                            // private coordinates
   public:
     Point (int a=0, int b=0)             // general constructor
      { x = a;  y = b; 
        cout << " Created: x= " << x << " y=" << y << endl; } 
     Point (const Point& pt)              // copy constructor
      { x = pt.x;  y = pt.y;
        cout << " Copied: x= " << x << " y=" << y << endl; } 
     void operator = (const Point& pt)    // assignment operator
      { x = pt.x;  y = pt.y;
        cout << " Assigned: x= " << x << " y=" << y << endl; } 
     void set (int a, int b)              // modifier function
       { x = a;  y = b; } 
     void move (int a, int b)             // modifier function
       { x += a;  y += b; } 
     void get (int& a, int& b) const      // selector function
       { a = x;  b = y; } } ;

   class Rectangle {
     Point pt1, pt2;     // top-left, bottom-right corner points
     int thickness;      // thickness of the rectangle border
   public:
     Rectangle (const Point& p1, const Point& p2, int width=1);
     void move(int a, int b);             // move both points
     bool pointIn(const Point& pt) const; // point in rectangle?
      } ;

  Rectangle::Rectangle(const Point& p1, const Point& p2,int w) 
	  : thickness(w), pt1(p1), pt2(p2)    // initialization list
  {  }                                    // empty member body

  void Rectangle::move(int a, int b)  
    { pt1.move(a,b);  pt2.move(a,b); }    // pass buck to Point

  bool Rectangle::pointIn(const Point& pt) const // is point in?
   { int x,y,x1,y1,x2,y2;       // coordinates of pt and corners
     pt.get(x,y);               // get parameter's coordinates
     pt1.get(x1,y1);  pt2.get(x2,y2);   // get data from corners
     bool xIsBetweenBorders = (x1<x && x<x2) || (x2<x && x<x1);
     bool yIsBetweenBorders = (y>y1 && y<y2) || (y<y1 && y>y2);
     return (xIsBetweenBorders && yIsBetweenBorders); } 

int main()
{ Point p1(20,40), p2(70,90); // top-left, bottom-right corners
  Point point(100,120);    // point to catch with the rectangle
  Rectangle rec(p1,p2,4);  // NO wasted constructor calls
  point.move(-25,-15);     // move the point around the screen
  rec.move(10,20);         // 10 pixels to right, 20 pixels down
  if (rec.pointIn(point)) cout << " Point is in\n"; // is point?
  return 0;
  }

