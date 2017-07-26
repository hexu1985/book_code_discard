// Listing 5.6. A simple example of array overflow

#include <iostream>  
using namespace std;

int main()
{ 
  char first[6], last[6];      // are not these arrays too short?
  cout << "Enter first name: ";    // I enter "John\0" (5 symbols)
  cin >> first;                // no protection against overflow
  cout << "Enter last name: ";   // I enter "Johnson\0" (8 symbols)
  cin >> last;                 // no protection against overflow
  cout << first << " " << last << endl; // just to check results
  return 0;
  }
