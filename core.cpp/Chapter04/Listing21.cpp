// Listing 4-21. Computing sum of squares using the 'for' loop.

#include <iostream>
using namespace std;

int main ()
{ 
  int sum=0, num;
  cout << "\nEnter the number of squares to add: ";
  cin >> num;
  for (int n = 1; n <= num; n++)
    { sum += n * n; }
  cout << "Total of squares is " << sum << endl;
  return 0;
 } 
