// Listing 8.5.	Example of pushing responsibility from client to server

#include <iostream> 
using namespace std;

bool isLeap(int year)                // even fewer parameters
  { int remainder=year%4;  // do not separate what belongs together
    if (remainder != 0)
       return false;
    else if (year%100==0 && year%400!=0)
       return false;
    else 
       return true; }

int main()
{ int year;                          // local data - no remainder
  cout << "Enter the year:  ";
  cin >> year;                       // input variable is set
  if (isLeap(year))                  // output variable is used
    cout << year << " is a leap year\n";
  else
    cout << year << " is not a leap year\n";
  return 0;
  }
