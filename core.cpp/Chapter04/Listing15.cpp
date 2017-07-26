// Listing 4-15. The do-while loop without the prime read.

#include <iostream>
using namespace std;

int main ()
{ 
  double total, amount;  int count;
  total = 0.0;  count = 0;   // initialize current data
do {
  cout << "Enter amount (negative or zero to end): ";
  cin >> amount;           // enter (change) current data
  if (amount > 0)          // check for end of data
  { total += amount;       // process current data
    count++; }             
   } while (amount > 0);   // evaluate current data
  cout << "\nTotal of " << count << " transactions is "
       << total << endl; 
  return 0;
}
