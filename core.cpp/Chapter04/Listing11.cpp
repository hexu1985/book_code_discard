// Listing 4-11. Implementing the while loop with a negative or zero sentinel value.

#include <iostream>
using namespace std;

int main ()
{ 
  double total, amount;  int count;
  total = 0.0;  count = 0;   // different initialization 
  amount = 1.0;              // an artificial trick: why 1 and not 10?
  while (amount > 0)         // evaluate current data 
    { cout << "Enter amount (negative or zero to end): ";
      cin >> amount;         // enter current data
      total += amount;       // process current data
      count++; }             // change current data
  cout << "\nTotal of " << count << " transactions is "
       << total << endl;
  return 0;
 }
