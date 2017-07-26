// Listing 16.6	Examples of using conversion constructors and conversion operators.

#include <iostream>   
using namespace std;

class String {
  int size;                       // string size
  char *str;                      // start of internal string
  void set(const char* s);        // private string allocation
public:
  String (const char* s = "")     // default and conversion
    { set(s); }
  String (const String &s)        // copy constructor
    { set(s.str); }
  ~String()                       // destructor
  { delete [ ] str; }
  String& operator = (const String& s);         // assignment
  operator int() const;           // current string length
  operator char* () const;        // return pointer to start
} ;

void String::set(const char* s)
   { size = strlen(s);            // evaluate size
     str = new char[size + 1];    // request heap memory
     if (str == 0) { cout << "Out of memory\n"; exit(0); }  
     strcpy(str,s); }             // copy client data to heap

String& String::operator = (const String& s)
{ if (this == &s) return *this;   // no work if self-assignment
  delete [ ] str;                 // return existing memory
  set(s.str);                     // allocate/set new memory
  return *this; }                 // to support chain assignment

String::operator int() const       // no change to String object
{ return size; }

String::operator char* () const       // object does not change
{ return str; }                     // return pointer to start

class Account {                     // base class of hierarchy
protected:
  double balance;                   // protected data
  char *owner;
public: 

  Account(const char* name, double initBalance)   // general
  { owner = new char[strlen(name)+1];   // allocate heap space
    if (owner == 0) { cout << "\nOut of memory\n";  exit(0); }
	strcpy(owner, name);         // initialize data fields
	balance = initBalance; } 

  Account(const String& s)
  { int len = s;                    // get the size of string
    owner = new char[len+1];        // allocate heap memory
    if (owner == 0) { cout << "\nOut of memory\n";  exit(0); }
    strcpy(owner, s);               // initialize data fields
    balance = 0; } 

  operator double () const          // object does not change
  { return balance; }               

  operator String () const          // create a String object
  { return owner; }                 // implicit conversion

  void operator -= (double amount) 
  { balance -= amount; }           // pop responsibility up

  void operator += (double amount)
  { balance += amount; }           // increment unconditionally
} ;

int main()
{ 
  String owner("Smith");            // conversion constructor
  Account a(owner);                 // conversion constructor
  a += 500;  a -=200;  a += 400;    // overloaded operators
  String s = a;                     // handle as a String value 
  double limit = 2 * a;             // handle as a double value
  cout << "Name: " << (char *)s << endl;  // explicit conversion
  cout << "Balance: " <<(double)a <<endl; // explicit conversion
  cout << "Credit limit: " << limit << endl;  
  return 0;
  }
