// Listing 4-19. A 'for' loop with comma operator in its initial expressions

#include <iostream>
using namespace std;

int main ()
{ 
  double total, amount;  int count; // no initialization 
  cout << "Enter amount (negative or zero to end): ";
  cin >> amount;           // enter current data
  for (total=0.0, count=0; amount>0; count++) 
  { total+=amount;
    cout << "Enter amount (negative or zero to end): ";
    cin >> amount; }       // change current data
  cout << "\nTotal of " << count << " transactions is "
       << total << endl; 
  return 0;
}
