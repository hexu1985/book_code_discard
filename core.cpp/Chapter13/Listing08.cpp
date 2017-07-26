//  Listing 13.8	Access to base members in a derived object under protected inheritance.

 #include <iostream> 
 using namespace std;
 
 class Point {                                 // base class
 protected:
   int x, y;                            // protected base data
 public:
   void set (int xi, int yi)
     { x = xi;  y = yi; }
   void get (int &xp, int &yp) const    // public base functions
     { xp = x;  yp = y; } } ;
 
 class VisiblePoint : protected Point { // protected inheritance
   int visible;
 
 public:      
    void show()
      { visible = 1; }
 
    void hide()
      { visible = 0; }
 
    void retrieve(int &xp, int &yp, int &vp) const
      { xp = x;  yp = y;       // access to protected data is OK
 //       get(xp,yp);          // no need for extra complexity
        vp = visible; } 
 
   void initialize(int xp, int yp, int vp) // new public service
     { x = xp;  y = yp;        // access to protected base data
       visible = vp; } } ;     // access to derived private data 
 
 int main ()
 { 
   VisiblePoint a,b;  int x, y, z; // define two derived objects
   b.initialize(20,40,1);          // initialize derived object
 // a.set(0,0);  b.set(20,40);     // now this is a syntax error
   a.hide();  b.show();            // derived public methods: OK 
 // a.get(x,y);                    // and this is a syntax error
   b.retrieve(x,y,z);              // derived public method: OK
   cout << " Point coordinates: x=" << x << "  y=" << y << endl;
   cout << " Point visibility:  visible=" << z << endl;  
   return 0;
   }
