// Listing 11.2.	Class String with dynamically allocated heap memory.

#include <iostream> 
using namespace std;

class String {
  char *str;                    // dynamically allocated char array
  int len;
public:
  String (int length=0);       // conversion/default constructor
  String(const char*);         // conversion constructor
 ~String ();                   // deallocate dynamic memory
  void modify(const char*);    // change the array contents
  char* show() const;          // return a pointer to the array
} ;

String::String(int length)
{ len = length;
  str = new char[len+1];       // default size is 1
  if (str==NULL) exit(1);      // test for success
  str[0] = 0; }                // empty string of 0 length is ok

String::String(const char* s)
{ len = strlen(s);             // measure length of incoming text
  str = new char[len+1];       // allocate enough heap space
  if (str==NULL) exit(1);      // test for success
  strcpy(str,s); }             // copy text into new heap memory

String::~String()
{ delete str; }       // return heap memory (not the pointer!)
 
void String::modify(const char a[]) // no memory management here
{ strncpy(str,a,len-1);             // protect from overflow
  str[len-1] = 0; }                 // terminate string properly

char* String::show() const        // not a good practice, but ok
{ return str; }

int main()
{ 
  String u("This is a test.");
  String v("Nothing can go wrong.");
  cout << " u = " << u.show() << endl;     // result is ok
  cout << " v = " << v.show() << endl;     // result is ok
  v.modify("Let us hope for the best.");   // input is truncated
  cout << " v = " << v.show() << endl; 
  strcpy(v.show(),"Hi there");             // bad practice
  cout << " v = " << v.show() << endl; 
  return 0;
  }

