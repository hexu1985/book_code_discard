// Listing 4-23.	Using the do-while loop for input validation.

#include <iostream>
using namespace std;

const int N = 5;

int main ()
{ 
  int num, error_flag;
  do {
    cout << "Enter number between 1 and " << N << " : ";
    cin >> num;
    if (num < 1 || num > N)
      { cout << "This is incorrect; please repeat.\n";
        error_flag = 1; }
    else
      error_flag = 0;
    } while (error_flag == 1);
  cout << "Your input is " << num << endl;
  return 0;
 } 
