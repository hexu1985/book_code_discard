// Listing 11.4	Initializing one object with data from another object.

#include <iostream> 
using namespace std;

class String {
  char *str;                  // dynamically allocated char array
  int len;
public:
  String (int length=0);      // conversion/default constructor
  String(const char*);        // conversion constructor
 ~String ();                  // deallocate dynamic memory
  void operator += (const String&); // concatenate another object
  void modify(const char*);         // change the array contents
  const char* show() const;   // return a pointer to the array
 } ;

String::String(int length)
{ len = length;
  str = new char[len+1];
  if (str==NULL) exit(1);
  str[0] = 0; }        // empty string of zero length is ok, too

String::String(const char* s)
{ len = strlen(s);         // measure the length of incoming text
  str = new char[len+1];   // allocate enough heap space
  if (str==NULL) exit(1);  // test for success
  strcpy(str,s); }         // copy incoming text into heap memory

String::~String()
{ delete str; }        // return heap memory (not the pointer!)
 
void String::operator += (const String& s) // reference parameter
{ len = strlen(str) + strlen(s.str);       // total length
  char* p = new char[len + 1];   // allocate enough heap memory
  if (p==NULL) exit(1);                    // test for success
  strcpy(p,str);                 // copy the first part of result
  strcat(p,s.str);               // add the second part of result
  delete str;                              // important step
  str = p; }                         // now temp can disappear

const char* String::show() const     // protect data from changes
{ return str; }

void String::modify(const char a[])  // no memory management here
{ strncpy(str,a,len-1);             // protect from overflow
  str[len-1] = 0; }                 // terminate string properly

int main()
{ cout  << endl << endl;
  String u("This is a test. ");
  String v("Nothing can go wrong.");
  cout << " u = " << u.show() << endl;       // result is ok
  cout << " v = " << v.show() << endl;       // result is ok
  u += v;                                    // u.operator+=(s);
  cout << " u = " << u.show() << endl;       // result is ok
  cout << " v = " << v.show() << endl;   // ok: pass by reference
  v.modify("Let us hope for the best."); // no memory corruption
  { String t = v;                        // initialization
    cout << " t = " << t.show() << endl; // ok: correct result
    t.modify("Nothing can go wrong.");   // change both t and v
    cout << " t = " << t.show() << endl; // ok: correct result
    cout << " v = " << v.show() << endl; }   // v also changed
  cout << " v = " << v.show() << endl;   // t died, v is robbed
  return 0;
  } 

