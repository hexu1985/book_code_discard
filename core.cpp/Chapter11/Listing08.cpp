// Listing 11.8	Example of private prototypes to outlaw incorrect handling of objects

#include <iostream> 
using namespace std;

class Window {
  char *str;                 // dynamically allocated char array
  int len;
Window(const Window& w);              // private copy constructor
Window& operator = (const Window &w); // private assignment
public:
Window()
{ len = 0;  str = new char;  str[0]= 0 ; }   // empty string
~Window()
{ delete str; }                    // return heap memory
void operator += (const char s[])  // array parameter
{ len = strlen(str) + strlen(s);         
  char* p = new char[len + 1];     // allocate enough heap memory
  if (p==NULL) exit(1);                      
  strcpy(p,str);  strcat(p,s);     // form data from components
  delete str;  str = p; }          // hook up str to new data
const char* show() const             
{ return str; } } ;                // pointer to data

void display(const Window window)  // do not pass objects by value
{ cout << window.show(); }

int main()
{ Window w1;  w1 += "Welcome, Dear Customer!\n";   // reasonable
  Window w2 = w1;    // unreasonable usage: syntax error
  w2 = w1;           // even less reasonable usage: syntax error
  display(w2);       // pass by value: syntax error
  return 0;
  }

