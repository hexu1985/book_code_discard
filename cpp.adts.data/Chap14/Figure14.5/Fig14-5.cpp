/*--------------------------------------------------------------------
  Program to convert the base-ten representation of a positive integer to
  base two.  A BoundedStack stores the remainders produced by the 
  repeated-division algorithm.
 --------------------------------------------------------------------*/
#include <iostream>
using namespace std;
#include "BoundedStack.h"

int main()
{
  const int STACK_BOUND = 16;    // bound on number of stack elements
  int numBits;                   // number of bits in binary rep.
  cout << "How many bits do you want in the binary representations? ";
  cin >> numBits;
  unsigned number,               // the number to be converted
           remainder;            // remainder of number divided by 2
  char response;                 // user response
  do
  {
    BoundedStack<unsigned>       // bounded stack of remainders   
      stackOfRemainders(STACK_BOUND);
    cout << "Enter positive integer to convert: ";
    cin >> number;
    int count = 0;               // counts bits in binary representation
    while (number != 0)
    {
      remainder = number % 2;
      stackOfRemainders.push(remainder);
      count++;
      number /= 2;
    }
    stackOfRemainders.repeatedPush (0, numBits - count);
    cout << "Base-two representation: ";
    while (!stackOfRemainders.empty() )
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
