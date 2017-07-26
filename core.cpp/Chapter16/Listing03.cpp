// Listing 16.3	Example of using the increment operator with a pointer to internal data.

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
 int getSize() const;             // current string length
 char* reset() const; } ;         // reset to start of string

void String::set(const char* s)
 { size = strlen(s);              // evaluate size
   str = new char[size + 1];      // request heap memory
   if (str == 0) { cout << "Out of memory\n"; exit(0); }  
   strcpy(str,s); }               // copy client data to heap

String& String::operator = (const String& s)
{ if (this == &s) return *this;   // no work if self-assignment
  delete [ ] str;                 // return existing memory
  set(s.str);                     // allocate/set new memory
  return *this; }                 // to support chain assignment

int String::getSize() const       // no change to String object
{ return size; }

char* String::reset() const       // no change to String object
{ return str; }                   // return pointer to start

void printString(const String& data)    // no change to string 
{ char *p = data.reset();         // point to first character
  while (*p != 0)                 // go until end of characters
  { cout << *p;                   // print the current character
    ++p; }                        // point to the next character
  cout << endl; }

void modifyString(const String& data, const char text[]) // bad
{ char *p = data.reset();         // point to first character
  int len = strlen(text) + 1;     // set the iteration limit
  for (int i=0;  i < len;  i++)   // go over each character
  { *p = text[i];                 // copy the current character
    ++p; } }                      // point to the next character

int main()
{ 
  String data = "Hello World!";
  printString(data);               // good output
  modifyString(data,"How is weather?");
  printString(data);               // memory is corrupted
  return 0;
  }
