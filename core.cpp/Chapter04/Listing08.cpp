// Listing 4-8.	A Solution to the Leap Year Problem.

#include <iostream> 
using namespace std;

int main ()
{ 
  int year;
  cout << "Please enter year: ";
  cin >> year;
  if (year % 4 != 0)                // not dividable by 4, period
    cout <<"Year " << year <<" is not a leap year" << endl;
  else
    if (year % 100 == 0)
      if (year%400 == 0)            // dividable by 400 (hence, by 100)
        cout <<"Year " << year <<" is a leap year" << endl;
      else                         // dividable by 4 and by 100 but not by 400  
        cout <<"Year "<<year<<" is not a leap year" <<endl;
    else                           // dividable by 4 but not dividable by 100 
      cout << "Year " << year << " is a leap year" << endl;
  return 0;
}
