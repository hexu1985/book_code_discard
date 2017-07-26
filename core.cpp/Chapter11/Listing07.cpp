// Listing 11.7	Class String with the overloaded assignment operator.

#include <iostream> 
using namespace std;

class String {
  char *str;                // dynamically allocated char array
  int len;
  char* allocate(const char* s)     // private function
  { char *p = new char[len+1]; // allocate heap memory for object
    if (p==NULL) exit(1);   // test for success, quit if no luck
    strcpy(p,s);               // copy text into heap memory
	return p; }             // return pointer to heap memory
public:
  String (int length=0);       // conversion/default constructor
  String(const char*);              // conversion constructor
  String(const String& s);          // copy constructor
 ~String ();                        // deallocate dynamic memory
  void operator += (const String&); // concatenate another object
  String operator = (const String&);  // assignment operator
  void modify(const char*);         // change the array contents
  bool operator == (const String&) const; // compare contents 
  const char* show() const;         // return a pointer to array
 } ;

String::String(int length)
{ len = length;
  str = allocate(""); }    // copy empty string into heap memory

String::String(const char* s)
{ len = strlen(s);         // measure the length of incoming text
  str = allocate(s);       // allocate space, copy incoming text
  cout << " Created:  '" << str <<"'\n"; }

String::String(const String& s)             // copy constructor
{ len = s.len;             // measure length of the source text
  str = allocate(s.str);   // allocate space, copy incoming text
  cout << " Copied:   '" << str <<"'\n"; }

String::~String()
{ delete str; }         // return heap memory (not the pointer!)
 
void String::operator += (const String& s) // reference parameter
{ len = strlen(str) + strlen(s.str);      // total length
  char* p = new char[len + 1];  // allocate enough heap memory
  if (p==NULL) exit(1);                   // test for success
  strcpy(p,str);                // copy the first part of result
  strcat(p,s.str);              // add the second part of result
  delete str;                             // important step
  str = p; }                              // now p can disappear

String String::operator = (const String& s)
{ if (&s == this) return *this;       // test for self-assignment
  delete str;            // you do not do it in copy constructor
  len = s.len;           // copy non-pointer data
  str = allocate(s.str); // allocate space, copy incoming text
  cout << " Assigned:  '" << str <<"'\n";  // for debugging only
  return *this; }        // return the target object to client

bool String::operator==(const String& s) const // compare contents 
{ return strcmp(str,s.str)==0; } // strcmp returns 0 if the same

const char* String::show() const   // protect data from changes
{ return str; }

void String::modify(const char a[])        // no memory management here
{ strncpy(str,a,len-1);             // protect from overflow
  str[len-1] = 0; }                 // terminate string properly

String enterData()
{ cout << " Enter city to find: ";  // prompt the user
  char data[200];                   // crude solution
  cin >> data;                      // accept user input
  return String(data); }            // conversion constructor

int main()
{ cout  << endl << endl;
  enum { MAX = 4} ;
  String data[4];                   // database of objects
  char *c[4] = { "Atlanta", "Boston", "Chicago", "Denver" };
  for (int j=0; j<MAX; j++)
  { data[j] = c[j]; } // assignment: data[j].operator=(c[j]);
  String u;  int i;
  u = enterData();    // it needs assignment, no copy constructor
  for (i=0; i<MAX; i++)
  { if (data[i] == u) break; }      // if (data[i].operator==(u))
  if (i == MAX)
    cout << " City " << u.show() << " is not found\n";
  else
    cout << " City " << u.show() << " is found\n";
  return 0;
  }

