// Listing 8.4.	Example of using a return value rather than an output pa-rameter

#include <iostream> 
using namespace std;

bool isLeap(int year, int remainder)    // fewer parameters
  { if (remainder != 0)
       return false;
    else if (year%100==0 && year%400!=0)
       return false;
    else 
       return true; }

int main()
{ int year, remainder;               // local input variables
  bool leap;                         // local output variable
  cout << "Enter the year:  ";
  cin >> year;                       // input variables are set
  remainder = year % 4;
  leap = isLeap(year,remainder);     // output variable is set
  if (leap)                          // output variable is used
	cout << year << " is a leap year\n";
  else
	cout << year << " is not a leap year\n";
  return 0;
  }
