// Listing 4-22. A 'for' loop that degenerates to an empty statement .

#include <iostream>
using namespace std;

int main ()
{ 
  int num;  
  cout << "\nEnter the number of squares to add: ";
  cin >> num;
  for (int sum = 0, n = 1; n <= num; sum+=n*n, n++);             // !!
  cout << "Total of squares is " << sum << endl;
  return 0;
 } 
