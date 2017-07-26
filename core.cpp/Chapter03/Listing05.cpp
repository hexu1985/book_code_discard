// Listing 3.5:	Demonstration of the increment operator.

#include <limits>
#include <iostream>
using namespace std;

int main(void)
{ 
  int num = INT_MAX - 2;
  int cnt = 0;
  cout << "Integer overflow in C++:\n" << endl; 
  cout << "Incrementing from " << num << endl;
  while (cnt < 5)
  { num++;  cnt++;               // increment operators
    cout << cnt << "   " << num << endl; }
  cout << "Thank you for worrying about integer limits\n" << endl;
  return 0;
    }
