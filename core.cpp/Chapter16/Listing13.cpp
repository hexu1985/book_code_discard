// Listing 16.13	Overloading the input and output operators for a programmer-defined type.

#include <iostream.h>
#include <string.h>  
#include <stdlib.h> 
//#include <iostream>
//using namespace std;

class String {
  int size;                       // string size
  char *str;                      // start of internal string
  void set(const char* s);        // private string allocation
public:
friend istream& operator >> (istream& in, String& s);
friend ostream& operator << (ostream& out, const String& s);
  String (const char* s = "")     // default and conversion
    { set(s); }
  String (const String &s)        // copy constructor
    { set(s.str); }
  ~String()                       // destructor
  { delete [ ] str; }
  String& operator = (const String& s);         // assignment
  char* get () const              // return pointer to start
  { return str; }
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

istream& operator >> (istream& in, String& s) 
{ char name[80];                  // local storage for data
  in >> name;                     // accept data
  delete [] s.str;                // return existing memory
  s.set(name);                    // allocate/init new memory
  return cin; }

ostream& operator << (ostream& out, const String& s)
 { return out << s.str; }         // it is allowed to a friend

int main ()
{ cout << endl << endl;
  String s;  int qty;             // local data
  cout << "Enter customer name and quantity:  ";
  cin >> s >> qty;                // accept name and quantity
  cout << "The customer name is: " << s << endl;  // very nice
  cout << "Quantity ordered is:  " << qty << endl;
  return 0;
  } 
