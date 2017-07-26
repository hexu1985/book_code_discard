// Listing 13.17	Using inheritance for classes with dynamic memory management

#include <iostream> 
using namespace std;

class Name {                      // Base class
  char *name;                     // dynamic memory management
protected:
  Name(char nm[]);                // prevent using the objects
public:
 ~Name();                           // return dynamic memory
  const char* get() const; } ;      // access the contents

Name::Name(char nm[])
{ name = new char[strlen(nm)+1];    // allocate heap space
   if (name == NULL) { cout << "Out of memory\n";  exit(1); }
   strcpy(name,nm); }               // initialize heap memory

const char* Name::get () const
{ return name; }                    // access private data

Name::~Name() 
   { delete [] name; }              // return object data

class Address : public Name {            // Derived class
  char *email;
  Address(const Address&);               // no value semantics
  void operator = (const Address&);
public:
  Address(char name[], char address[]);  // allocate heap space
 ~Address();
  void show() const; } ;                 // display object data

Address::Address(char nm[], char addr[]) : Name(nm)
{ email = new char[strlen(addr)+1];
  if (email == NULL) { cout << "Out of memory\n";  exit(1); }
  strcpy(email,addr); }

Address::~Address()                      // return object memory
{ delete [] email; }

void Address::show() const               // display object data
{ cout << " Name:  " << Name::get() << endl;
  cout << " Email: " << email << endl << endl; }

int main ()
{ 
  Address x("Shtern", "shtern@bu.edu");   // client code
  x.show();  
  return 0;
  }
