// Listing 11.6	Use of copy constructor to return an object from a function.

#include <iostream> 
using namespace std;

class String {
  char *str;                // dynamically allocated char array
  int len;
  char* allocate(const char* s)     // private function
  { char *p = new char[len+1]; // allocate heap memory for object
    if (p==NULL) exit(1);   // test for success, quit if no luck
    strcpy(p,s);                    // copy text into heap memory
    return p; }                // return pointer to heap memory
public:
  String (int length=0);       // conversion/default constructor
  String(const char*);              // conversion constructor
  String(const String& s);          // copy constructor
 ~String ();                        // deallocate dynamic memory
  void operator += (const String&); // concatenate another object
  void modify(const char*);         // change the array contents
  bool operator == (const String&) const; // compare contents 
  const char* show() const;    // return a pointer to the array
 } ;

String::String(int length)
{ len = length;
  str = allocate("");      // copy empty string into heap memory
  cout << " Originate:  '" << str <<"'\n"; }

String::String(const char* s)
{ len = strlen(s);             // measure length of incoming text
  str = allocate(s);                 // allocate space, copy text
  cout << " Created:  '" << str <<"'\n"; }

String::String(const String& s)              // copy constructor
{ len = s.len;               // measure length of the source text
  str = allocate(s.str);             // allocate space, copy text
  cout << " Copied:   '" << str <<"'\n"; }

String::~String()
{ delete str; }          // return heap memory (not the pointer!)
 
void String::operator += (const String& s) // reference parameter
{ len = strlen(str) + strlen(s.str);         // total length
  char* p = new char[len + 1];   // allocate enough heap memory
  if (p==NULL) exit(1);                      // test for success
  strcpy(p,str);                 // copy the first part of result
  strcat(p,s.str);               // add the second part of result
  delete str;                                // important step
  str = p; }                     // now pointer p can disappear

bool String::operator==(const String& s) const // compare contents 
{ return strcmp(str,s.str)==0; } // strcmp returns 0 if the same

const char* String::show() const    // protect data from changes
{ return str; }

void String::modify(const char a[]) // no memory management here
{ strncpy(str,a,len-1);             // protect from overflow
  str[len-1] = 0; }                 // terminate string properly

String enterData()
{ cout << " Enter city to find: ";       // prompt the user
  char data[200];                        // crude solution
  cin >> data;                           // accept user input
  return String(data); }                 // call the constructor

int main()
{ enum { MAX = 4} ;
  String data[4];                        // database of objects
  char *c[4] = { "Atlanta", "Boston", "Chicago", "Denver" }; 
  for (int j=0; j<MAX; j++)
  { data[j] += c[j]; }              // data[j].operator+=(c[j]);
  String u = enterData();    // crashes without copy constructor
  int i;
  for (i=0;  i < MAX;  i++)  // i is defined outside of the loop
    { if (data[i] == u) break; }    // break if string found
  if (i == MAX)                     // how did we get here?
    cout << " City " << u.show() << " is not found\n";
  else
    cout << " City " << u.show() << " is found\n";
  return 0;
  } 

