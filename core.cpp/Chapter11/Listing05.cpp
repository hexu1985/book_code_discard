// Listing 11.5	Use of copy constructor to initialize one object with data from another.

#include <iostream> 
using namespace std;

class String {
  char *str;                 // dynamically allocated char array
  int len;
  char* allocate(const char* s)      // private function
  { char *p = new char[len+1]; // allocate heap memory for object
    if (p==NULL) exit(1);    // test for success, quit if no luck
    strcpy(p,s);             // copy text into heap memory
    return p; }              // return pointer to heap memory
public:
  String (int length=0);       // conversion/default constructor
  String(const char*);         // conversion constructor
  String(const String& s);     // copy constructor
 ~String ();                        // deallocate dynamic memory
  void operator += (const String&); // concatenate another object
  void modify(const char*);         // change the array contents
  const char* show() const;    // return a pointer to the array
 } ;

String::String(int length)
{ len = length;
  str = allocate(""); }    // copy empty string into heap memory

String::String(const char* s)
{ len = strlen(s);         // measure the length of incoming text
  str = allocate(s); }     // allocate space, copy incoming text

String::String(const String& s)            // copy constructor
{ len = s.len;             // measure length of the source text
  str = allocate(s.str); } // allocate space, copy incoming text

String::~String()
{ delete str; }         // return heap memory (not the pointer!)
 
void String::operator += (const String& s) // reference parameter
{ len = strlen(str) + strlen(s.str);       // total length
  char* p = new char[len + 1];  // allocate enough heap memory
  if (p==NULL) exit(1);         // test for success
  strcpy(p,str);                // copy the first part of result
  strcat(p,s.str);              // add the second part of result
  delete str;                              // important step
  str = p; }                    // now pointer p can disappear

const char* String::show() const     // protect data from changes
{ return str; }

void String::modify(const char a[])  // no memory management here
{ strncpy(str,a,len-1);             // protect from overflow
  str[len-1] = 0; }                 // terminate string properly

int main()
{ cout  << endl << endl;
  String u("This is a test. ");
  String v("Nothing can go wrong.");
  cout << " u = " << u.show() << endl;          // result is ok
  cout << " v = " << v.show() << endl;          // result is ok
  u += v;                                // u.operator+=(v);
  cout << " u = " << u.show() << endl;   // result is ok
  cout << " v = " << v.show() << endl;   // ok: pass by reference
  v.modify("Let us hope for the best."); // no memory corruption
  { String t = v;                        // call copy constructor
    cout << " t = " << t.show() << endl;   // ok: correct result
    t.modify("Nothing can go wrong.");     // change only t
    cout << " t = " << t.show() << endl;   // ok: correct result
    cout << " v = " << v.show() << endl; } // v did not changed
  cout << " v = " << v.show() << endl;     // t died, v is intact
  return 0;
  } 

