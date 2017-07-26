// Listing 4-18. Implementing transaction processing in a 'for' loop. 

#include <iostream>
using namespace std;

int main ()
{ 
  double total, amount;  int count;
  total = 0.0;             // different initialization 
  cout << "Enter amount (negative or zero to end): ";
  cin >> amount;           // enter current data
  for (count=0; amount>0; count++) // three expressions 
  { total += amount;       // process current data
    cout << "Enter amount (negative or zero to end): ";
    cin >> amount; }       // change current data
  cout << "\nTotal of " << count << " transactions is "
       << total << endl; 
  return 0;
}
