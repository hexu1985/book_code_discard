//--- Program to test BigInt class.

#include <iostream>
using namespace std;

#include "BigInt.h"

int main()
{
   char response;
   do
   {
      BigInt number1, number2;
      cout <<"Enter a big integer:\n";
      cin >> number1;
      cout <<"Enter another big integer:\n";
      cin >> number2;

      cout << "The sum of\n\t"
           << number1 << "\nand\n\t" << number2
           << "\nis\n\t" << number1 + number2 << endl;

      cout << "\nAdd more integers (Y or N)? ";
      cin >> response;
   }
   while (response == 'y' || response == 'Y');
}
