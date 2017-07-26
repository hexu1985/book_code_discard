// Listing 13.10	Access to Base members in the inheritance hierarchy where the Derived class inherits from its Base in private mode.

 #include <iostream> 
 using namespace std;
 
 class Base {
    private: int privB;      // accessed from Base only
    protected: int protB;    // accessed from Base and Derived
    public: void publB()     // accessed from Base and Derived
    { privB = 0; protB = 0; } } ;  // OK to access its own data
 
 class Derived : private Base {    // private inheritance
    private:  int privD;
    protected: int protD;
    public: void publD()
    { privD = 0;  protD = 0; // OK to access its own data
      protB = 0;             // OK to access inherited members
  //  privB = 0;     // not OK to access its inherited members
 		   } } ; 
 
 class Derived1 : public Derived { // class derived from derived
 public: void publDD()
 { // privD = 0;     // no access to private "base" data
   protD = 0;        // OK to access protected "base" data
   publD();          // OK to access public "base" data
 //  protB = 0;      // no access to any part of "private base"
 //  publB();        // no access to any part of "private base"
 } } ;
 
 class Client {
 public: Client()
 { Derived d;  Base b;  // objects of derived and base classes
   d.publD();           // public part of Derived class: OK
 //  d.publB();         // public Base part of Derived: not OK 
 //  d.privD = d.protD = 0; // non-public part of Derived: no 
 //  d.privB=d.protB=0; // non-public Base part of Derived: no 
   b.publB(); }         // public Base part of Base object: OK
     } ;
 
 int main()
 { Client c;            // create the object, run the program
   return 0;
   }

