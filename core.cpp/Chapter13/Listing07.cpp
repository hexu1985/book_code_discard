//  Listing 13.7	Access to Base and Derived members of the Derived object for the Derived class and for the client code when the mode of derivation is protected.

 #include <iostream> 
 using namespace std;
 
 class Base {
    private: int privB;       // accessed from Base only
    protected: int protB;     // accessed from Base and Derived
    public: void publB()      // no access from Derived client
    { privB = 0; protB = 0; } } ;  // OK to access its own data
 
 class Derived : protected Base {      // protected inheritance
    private:  int privD;
    protected: int protD;
    public: void publD()
    { privD = 0;  protD = 0;  // OK to access its own data
      protB = 0;              // access to inherited members
 //   privB = 0;              // no access its inherited members
       } } ;
 
 class Client {                        // Client code
 public: Client()
 { Derived d;  Base b;       // objects of Derived, Base classes
   d.publD();                // public part of Derived class: OK
 //  d.publB();              // no access to public Base part 
 //  d.privD = d.protD = 0;  // non-public Derived parts: not OK
 //  d.privB=d.protB=0;      // non-public Base parts: no access 
   b.publB(); }              // Base object: public part is OK 
       } ;
 
 int main()
 { Client c;               // create the object, run the program
   return 0;
   }

