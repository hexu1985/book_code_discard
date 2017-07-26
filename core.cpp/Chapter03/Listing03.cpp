// Listing 3.3:	Negative values in an unsigned variable.

#include <limits>
#include <iostream>
using namespace std;

int main(void)
{ 
  int unsigned num = 2;
  int cnt = 0;
  cout << "Negative values in an unsigned variable\n" << endl; 
  cout << "Count down starting with +1\n" << endl;
  while (cnt < 5)
  { num = num - 1;
    cnt = cnt + 1; 
    cout << cnt << "   " << num << endl; }
  cout << "Thank you for worrying about integer limits\n" << endl;
  return 0;
    }
