// Listing 13.5	Access to Base and Derived members in a derived object
// for the Derived class and for client code under public inheritance.

 #include <iostream> 
 using namespace std;
 
 class Base {
    private: int privB;     // accessed from Base only
    protected: int protB;   // accessed from Base and Derived
    public: void publB()    // access from Base, Derived, Client
    { privB = 0; protB = 0; } } ;  // OK to access its own data
 
 class Derived : public Base {     // public mode of inheritance
    private:  int privD;
    protected: int protD;
    public: void publD()
    { privD = 0;  protD = 0; // OK to access its own data
      protB = 0;             // OK to access inherited members
 //   privB = 0;             // no access to inherited members
       } } ;
 
 class Client {
 public: Client()                 // Client class constructor
 { Derived d;              // object of the derived class
   d.publD();              // OK to access public services
   d.publB();              // OK to access public Base services 
//   d.privD = d.protD = 0;  // no access to non-public services 
//   d.privB=d.protB=0; }    // no access non-public Base services 
		 }
    } ;
 
 int main()
 { Client c;               // create the object, run the program
   return 0;
   } 

