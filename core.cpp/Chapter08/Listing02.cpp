// Listing 8.2.	Example of explicit coupling through parameters

#include <iostream> 
using namespace std;

void isLeap(int year, int remainder, bool &leap) // parameters
// inputs: year, remainder; output: leap
  { if (remainder != 0)
       leap = false;
    else if (year%100==0 && year%400!=0)
       leap = false;
    else 
       leap = true; }

int main()
{ int year, remainder;               // local input variables
  bool leap;                         // local output variable
  cout << "Enter the year:  ";
  cin >> year;                       // input variables are set
  remainder = year % 4;
  isLeap(year,remainder,leap);       // output variable is set
  if (leap)                          // output variable is used
	cout << year << " is a leap year\n";
  else
	  cout << year << " is not a leap year\n";
  return 0;
  }
