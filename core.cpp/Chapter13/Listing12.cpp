//  Listing 13.12	Example of using the default mode of inheritance for classes.

  class Base {
    private: int privB;      // accessed from Base only
    protected: int protB;    // accessed from Base and Derived
    public: void publB()     // accessed from Base and Derived
    { privB = 0; protB = 0; } } ; // OK to access its own data
 
 class Derived : Base {           // it is private by default
    private:  int privD;
    protected: int protD;
    public: void publD()
    { privD = 0;  protD = 0; protB = 0; } } ; // OK to access 
 
 int main()
 { Derived d;                   // object of the derived class
   d.publD();      // OK to access public part of Derived class
 //  d.publB();    // not OK to access public part of Base class
   return 0;
   }
