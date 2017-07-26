// Listing 9.4.	Memory management by client code rather than by server object.

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
  strcpy(contents, name); }         // standard set of actions

void Name::show_name()
{ cout <<contents << "\n"; }

Name::~Name()                         // destructor
{ delete contents; }             // it deletes heap memory, not the pointer

void Client()
{ Name n1("Jones");                      // conversion constructor is called
  Name *p=(Name*)malloc(sizeof(Name));   // no constructor is called
  p->contents = new char[strlen("Smith")+1];    // allocate dynamic memory
  if (p->contents == NULL)                      // 'new' was not successful
    { cout << "Out of memory\n";  exit(1); }    // give up
  strcpy(p->contents, "Smith");          // 'new' was successful
  n1.show_name();  p->show_name();       // use the objects
  delete p->contents;                    // avoid memory leak
  free (p);                              // notice the sequence of actions 
  }               // p is deleted, destructor for object n1 is called

int main()              // pushing responsibility to server functions
{ Client();
  return 0;
  }
