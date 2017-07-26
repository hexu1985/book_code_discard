// Listing 8.3.	Example of merging parameters into a structure

#include <iostream> 
using namespace std;

struct YearData
{ int year, remainder;
  bool leap; } ;

void isLeap(YearData &data)         // one parameter only
  { if (data.remainder != 0)
       data.leap = false;
    else if (data.year%100==0 && data.year%400!=0)
       data.leap = false;
    else 
       data.leap = true; }

int main()
{ YearData data;                     // local variable
  cout << "Enter the year:  ";
  cin >> data.year;                  // input fields are set
  data.remainder = data.year % 4;
  isLeap(data);                      // output field is set
  if (data.leap)                     // output field is used
	cout << data.year << " is a leap year\n";
  else
	  cout << data.year << " is not a leap year\n";
  return 0;
  }
