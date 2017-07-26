// Listing 16.4	Example of using the increment operator as a message to the object.

#include <iostream>   
using namespace std;

class String {
  int size;                       // string size
  char *str;                      // start of internal string
  char *ptr;                      // pointer to current symbol
  void set(const char* s);        // private string allocation
public:
  String (const char* s = "")     // default and conversion
    { set(s); }
  String (const String &s)        // copy constructor
    { set(s.str); }
  ~String()                       // destructor
  { delete [ ] str; }
  String& operator = (const String& s);         // assignment
 char* operator++();              // prefix increment operator
 int getSize() const;             // current string length
 char* reset(); } ;               // no const: object changes

void String::set(const char* s)
   { size = strlen(s);            // evaluate size
     str = new char[size + 1];    // request heap memory
     if (str == 0) { cout << "Out of memory\n"; exit(0); }  
     strcpy(str,s);               // copy client data to heap
     ptr = str;   }               // initialize running pointer

String& String::operator = (const String& s)
{ if (this == &s) return *this;   // no work if self-assignment
  delete [ ] str;                 // return existing memory
  set(s.str);                     // allocate/set new memory
  return *this; }                 // to support chain assignment

int String::getSize() const       // no change to String object
{ return size; }

char* String::reset()             // no const: object changes
{ ptr = str;                      // set current pointer to start
  return str; }                   // return pointer to start

char* String::operator ++()       // increment then access
{ if (ptr - str < size)           // check if room is available
    return ++ptr;                 // pointer to next character
  else 
     { *ptr = 0;                  // set the terminating zero
       return ptr; } }            // do not move it if at end

void printString(String& data)    // no const: string changes
{ char *p = data.reset();         // point to first character
  while (*p != 0)                 // go until end of characters
  { cout << *p;                   // print the current character
    p = ++data; }                 // point to the next character
  cout << endl; }

void modifyString(String& data, const char text[]) 
{ char *p = data.reset();         // point to first character
  int len = strlen(text) + 1;     // set the iteration limit
  for (int i=0;  i < len;  i++)   // go over each character
  { *p = text[i];                 // copy the current character
    p = ++data; } }               // point to the next character

int main()
{ 
  String data = "Hello World!";
  printString(data);               // good output
  modifyString(data,"How is weather?");
  printString(data);               // memory is NOT corrupted
  return 0;
  }
