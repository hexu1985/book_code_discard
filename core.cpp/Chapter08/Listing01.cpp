// Listing 8.1.	Example of implicit coupling through global variables

#include <iostream> 
using namespace std;

int year, remainder;                    // global input variables
bool leap;                              // global output variable

void isLeap()          // inputs: year, remainder; output: leap
  { if (remainder != 0)                  // access global variables
      leap = false;        // if not divisible by 4, it is not leap year
    else if (year%100==0 && year%400!=0) // access global variables
      leap = false;   // divisible by 100 but not by 400: not leap year
    else 
      leap = true; }       // otherwise, it is a leap year

int main()
{ cout << "Enter the year:  ";
  cin >> year;                 // prompt the user, enter data
  remainder = year % 4;                 // access global variables
  isLeap();                    // define whether it is a leap year
  if (leap)
    cout << year << " is a leap year\n";    // print results
  else
    cout << year << " is not a leap year\n";
  return 0;
  }

