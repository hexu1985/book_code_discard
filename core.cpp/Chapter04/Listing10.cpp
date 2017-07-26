// Listing 4-10. A while loop with an infinite number of iterations.

#include <iostream>
using namespace std;

int main ()
{ 
  double total, amount;  int count;
  total = 0.0;  count = 1;                     // initialize current data 
  while (count <= 5)                           // evaluate current data 
    { cout << "Enter the amount:  ";
      cin >> amount;                           // enter current data
      total += amount; }                       // process current data
  cout<< "\nTotal of 5 transactions is "<<total << endl;
  return 0;
 }
