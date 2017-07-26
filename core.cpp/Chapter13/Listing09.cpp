// Listing 13.9	Access to base members in a derived object under protected inheritance.

 #include <iostream> 
 using namespace std;
 
 class Point {                             // component class
 private:
   int x, y;                               // private data
 public:
   void set (int xi, int yi)
     { x = xi;  y = yi; }
   void get (int &xp, int &yp) const       // public method
     { xp = x;  yp = y; } } ;
 
 class VisiblePoint {            // no inheritance, composition
     Point pt;                             // private component 
     int visible;
 
 public:      
    void show()                        // new service to client
      { visible = 1; }
 
    void hide()                        // new service to client
      { visible = 0; }
 
    void retrieve(int &xp, int &yp, int &vp) const  // replace
      { pt.get(xp,yp);      // services are hidden from client
        vp = visible; } 
 
    void initialize(int xp, int yp, int vp)         // replace
     { pt.set(xp,yp);       // services are hidden from client
       visible = vp; } } ;  // just like private data are hidden 
 
 int main ()
 { 
   VisiblePoint b;  int x, y, z;       // define an aggregate object
   b.initialize(20,40,1);            // aggregate service
   b.show();                           // aggregate service
   b.retrieve(x,y,z);                  // aggregate service
   cout << " Point coordinates: x=" << x << "  y=" << y << endl;
   cout << " Point visibility:  visible=" << z << endl;    
   return 0;
   }
