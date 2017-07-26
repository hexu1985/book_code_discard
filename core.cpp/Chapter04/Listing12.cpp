// Listing 4-12. Implementing the while loop with the prime read.

#include <iostream>
using namespace std;

int main ()
{ 
  double total, amount;  int count;
  total = 0.0;  count = 0;                // different initialization 
  cout << "Enter amount (negative or zero to end): ";
  cin >> amount;                          // enter current data (first time)
  while (amount > 0)                      // evaluate current data 
  { total += amount;                      // process current data
    count++;               // change current data
    cout << "Enter amount (negative or zero to end): ";
    cin >> amount; }                      // changeenter current data
  cout << "\nTotal of " << count << " transactions is "
       << total << endl;
  return 0;
 }
