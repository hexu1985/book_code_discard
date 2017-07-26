// Listing 13.6	Access to base members in a derived object under public inheritance.

 #include <iostream> 
 using namespace std;
 
 class Point {                           // base class
   int x, y;                             // private base data
 public:
   void set (int xi, int yi)
     { x = xi;  y = yi; }
   void get (int &xp, int &yp) const     // public base methods
     { xp = x;  yp = y; } } ;
 
 class VisiblePoint : public Point {     // colon: before public
   int visible;
 
 public:                                 // colon: after public
    void show()
      { visible = 1; }
 
    void hide()
      { visible = 0; }
  
    void retrieve(int &xp, int &yp, int &vp) const
      {// xp = x;  yp = y;       // syntax error: comment it out!
        get(xp,yp);            // base public method is accessed
        vp = visible; } } ;    // derived private data: OK
 
 int main ()
 { 
   VisiblePoint a,b;  int x,y,z; // define two derived objects
   a.set(0,0);  b.set(20,40);    // call base public function
   a.hide();  b.show();          // call derived public methods
   a.get(x,y);                   // call base public function
   b.retrieve(x,y,z);            // call derived public method
   cout << " Point coordinates: x=" << x << "  y=" << y << endl;
   cout << " Point visibility:  visible=" << z << endl;  
   return 0;
   }

