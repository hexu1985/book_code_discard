// Listing 5.8. An example of preventing array overflow in concatenation

#include <iostream>  
#include <cstring>                  // notice a new header file
using namespace std;

int main()
{ 
  char first[6], last[6], name[10];
  cout << "Enter first name: ";
  cin.get(first,6); cin.ignore(200,'\n'); // it has to remove CR
  cout << "Enter last name: "; 
  cin.get(last,6); cin.ignore(200,'\n');  // it stops at first CR
  cout << first << " " << last << endl;  
//  strncpy(name,last,4);       // no null if length>=count
  strcpy(name,last);
  cout << "After copy: " << name << endl;
  strcat(name,", ");
  strncat(name,first,3);
  cout << "Customer: " << name << endl;
  cout << first << " " << last << endl;  // "just in case"
  return 0;
  }
