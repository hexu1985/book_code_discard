
/*--------------------------------------------------------------------------
  Program to convert the base-ten representation of a positive integer to
  base two.  A BoundedStack stores the remainders produced by the repeated-
  division algorithm.
 -------------------------------------------------------------------------*/

#include <iostream>
using namespace std;
#include "BoundedStack.h"

int main()
{
  const int STACK_BOUND = 16;          // bound on number of stack elements
  unsigned number,                     // the number to be converted
           remainder;                  // remainder of number divided by 2
  char response;                       // user response
  do
  {
    BoundedStack<short int>
      stackOfRemainders(STACK_BOUND);   // bounded stack of remainders
    cout << "Enter positive integer to convert: ";
    cin >> number;
    while (number != 0)
    {
      remainder = number % 2;
      stackOfRemainders.push(remainder);
      number /= 2;
    }
    cout << "Base-two representation: ";
    while (!stackOfRemainders.empty())
    {
      remainder = stackOfRemainders.top();
      stackOfRemainders.pop();
      cout << remainder;
    }
    cout << endl;
    cout << "WARNING:  If a bounded stack overflow occurred,\n"
            "          some bits are missing in the representation.\n";

    cout << "\nMore (Y or N)? ";
    cin >> response;
  }
  while (response == 'Y' || response == 'y');
}
