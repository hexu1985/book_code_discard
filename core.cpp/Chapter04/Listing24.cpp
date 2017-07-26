// Listing 4-24.	Transaction processing with goto jumps.

#include <iostream>
using namespace std;

int main ()
{ 
  double total=0.0, amount; int count=0; // initialize
start:
  cout << "Enter amount (negative or zero to end): ";
  cin >> amount;         // enter (change) current data
  if (amount <= 0) goto finish; // evaluate current data 
  total += amount;       // process current data
  count++; 
  goto start;            // go back to the start of loop
finish:             
  cout << "\nTotal of " << count << " transactions is "
       << total << endl; 
  return 0;
}
