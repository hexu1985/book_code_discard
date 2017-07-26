// Listing 9.3.	Example of using the destructor to return heap memory allocated to named  and to unnamed objects.

#include <iostream> 
using namespace std;

struct Name {
    char *contents;             // public pointer to dynamic memory
  Name (char* name);            // or Name (char name []);
  void show_name();
  ~Name(); } ;                  // destructor eliminates memory leak

Name::Name(char* name)         // conversion constructor
{ int len = strlen(name);         // number of characters 
  contents = new char[len+1];     // allocate dynamic memory
  if (contents == NULL)           // 'new' was not successful
    { cout << "Out of memory\n";  exit(1); }  // give up
  strcpy(contents, name);          // standard set of actions
  cout << "object created: " << contents << endl; }   // debugging

void Name::show_name()
{ cout <<contents << "\n"; }

Name::~Name()                         // destructor
{ cout << "object destroyed: " << contents << endl;    // debugging
  delete contents; }        // it deletes heap memory, not pointer 'contents'

void Client()
{ Name n1("Jones");                      // conversion constructor is called
  Name *p = new Name("Smith");           // conversion constructor is called
  n1.show_name();  p->show_name();
  delete p;        // destructor for object pointed to by p is called
   }               // p is deleted, destructor for object n1 is called
 
int main()              // pushing responsibility to server functions
{ Client();
  return 0;
  }
