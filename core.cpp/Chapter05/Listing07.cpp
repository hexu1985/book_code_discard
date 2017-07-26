// Listing 5.7. An example of array overflow in concatenation

#include <iostream>       // or #include <iostream.h>  
#include <cstring>   // or #include <string.h> -               // notice a new header file
using namespace std;

int main()
{ 
  char first[6], last[6]; char name[10]; // name = last, first
  cout << "Enter first name: "; 
  cin.get(first,6); cin.ignore(2000,'\n'); // has to remove CR
  cout << "Enter last name: "; 
  cin.get(last,6); cin.ignore(2000,'\n'); // it stops at first CR
  cout << first << " " << last << endl;  
  strcpy(name,last);               // copy last[] into name[]
  strcat(name,", ");               // append a comma and a space
  strcat(name,first);              // append first[] to name[]
  cout << "Customer: " << name << endl;
  cout << first << " " << last << endl;  // "just in case"
  return 0;
  }
