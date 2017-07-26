// Listing 11.3	Overloaded concatenation function with a value parameter.

#include <iostream> 
using namespace std;

class String {
  char *str;                 // dynamically allocated char array
  int len;
public:
  String (int length=0);     // conversion/default constructor
  String(const char*);             // conversion constructor
 ~String ();                       // deallocate dynamic memory
  void operator += (const String); // concatenate another object
  void modify(const char*);        // change the array contents
  const char* show() const;        // return a pointer to array
 } ;

String::String(int length)
{ len = length;
  str = new char[len+1];
  if (str==NULL) exit(1);
  str[0] = 0; }               // empty string of zero length is ok

String::String(const char* s)
{ len = strlen(s);            // measure length of incoming text
  str = new char[len+1];      // allocate enough heap space
  if (str==NULL) exit(1);     // test for success
  strcpy(str,s); }       // copy incoming text into heap memory

String::~String()
{ delete str; }          // return heap memory (not the pointer!)
 
void String::operator += (const String s)  // pass by value
{ len = strlen(str) + strlen(s.str);       // total length
  char *p = new char[len + 1];  // allocate enough heap memory
  if (p==NULL) exit(1);         // test for success
  strcpy(p,str);                // copy the first part of result
  strcat(p,s.str);              // add the second part of result
  delete str;                              // important step
  str = p; }                               // now p can disappear

const char* String::show() const     // protect data from changes
{ return str; }

void String::modify(const char a[])  // no memory management here
{ strncpy(str,a,len-1);             // protect from overflow
  str[len-1] = 0; }                 // terminate string properly

int main()
{ String u("This is a test. ");
  String v("Nothing can go wrong.");
  cout << " u = " << u.show() << endl;      // result is ok
  cout << " v = " << v.show() << endl;      // result is ok
  u += v;                                   // u.operator+=(v);
  cout << " u = " << u.show() << endl;      // result is ok
  cout << " v = " << v.show() << endl;      // result is not ok
  v.modify("Let us hope for the best.");    // memory corruption
  cout << " v = " << v.show() << endl;      //   ????
  return 0;
  } 

