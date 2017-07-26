// Listing 5.14. Using union with a tag field to enforce access integrity

#include <iostream>  
#include <cstring> 
using namespace std;

union StreetOrPOB
   { char street[30];         // alternative interpretations
     long int POB; } ;

struct Address
{ char first[30];
  int kind;                   // 0: street address;  1: P.O.B. 
  StreetOrPOB second;         // either one or another meaning
  char third[30]; } ;

int main ()
{ 
  Address a1, a2;     
  strcpy(a1.first,"Doe, John");   // address with street
  strcpy(a1.second.street,"15 Oak Street");  a1.kind = 0;
  strcpy(a1.third,"Anytown, MA 02445");
  strcpy(a2.first,"King, Amy");
  a2.second.POB = 761; a2.kind = 1;      // address with POB
  strcpy(a2.third,"Anytown, MA 02445");
  cout << a1.first << endl;
  if (a1.kind == 0)               // check data interpretation
    cout << a1.second.street << endl;
  else
    cout << "P.O.B. " << a1.second.POB << endl;
  cout << a1.third << endl;
  cout << endl;
  cout << a2.first << endl;
  if (a2.kind == 0)               // check data interpretation
    cout << a2.second.street << endl;
  else
    cout << "P.O.B. " << a2.second.POB << endl;
  cout << a2.third << endl;
  return 0;
  }
