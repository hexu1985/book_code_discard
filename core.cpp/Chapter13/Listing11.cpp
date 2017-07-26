// Listing 13.11	Example of adjusting the access rights to Base members in the Derived class (private inheritance).

 #include <iostream> 
 using namespace std;
 
 class Base {
    private: int privB;       // accessed from Base only
    protected: int protB;     // accessed from Base and Derived
    public: void publB()      // accessed from Base and Derived
    { privB = 0; protB = 0; } } ;  // OK to access its own data
 
 class Derived : private Base {     // private inheritance
    private:  int privD;
    protected: int protD;
    protected:
      Base::protB;           // available for further derivation
   public:
     Base::publB;            // available for client access
    public: void publD()
    { privD = 0;  protD = 0; // OK to access its own data
       protB = 0;         // OK to access its inherited members
  //   privB = 0;         // private inherited member: no access
     } } ;
 		   
 class Derived1 : public Derived { // class derived from derived
 public: void publDD()
 { // privD = 0;          // no access to private "base" data
   protD = 0;             // OK to access protected "base" data
   publD();               // OK to access public "base" data
   publB();               // OK if it is made public in Derived
   protB = 0;          // OK if it is made protected in Derived
     } } ;
 
 class Client {
 public: Client()
 { Derived d;  Base b;    // objects of derived and base classes
   d.publD();             // public part of Derived class: OK
   d.publB();             // OK if it is made public in Derived
 //  d.privD = d.protD = 0;  // non-public part of Derived: no 
 //  d.privB=d.protB=0;   // non-public Base part of Derived: no 
   b.publB();             // public Base part of Base object: OK
    } } ;
 
 int main()
 { Client c;              // create the object, run the program
   return 0;
   }
 

