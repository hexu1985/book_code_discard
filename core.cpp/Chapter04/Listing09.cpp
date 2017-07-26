// Listing 4-9.	An Optimized Solution to the Leap Year Problem.

#include <iostream>   
using namespace std;

int main ()
{ 
  int year;
  cout << "Please enter year: ";
  cin >> year;
  if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)
    cout <<"Year " << year << " is not a leap year" <<endl;
  else
    cout << "Year " << year << " is a leap year" << endl;
  return 0;
}
