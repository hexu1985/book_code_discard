// Listing 2-15. Client code for your first C++ class that combines data and functions

#include <iostream>
using namespace std;
#include "..\..\core c++\chapter 02\Listing 2.14.cpp"      // prototypes

int main(void)
{ 
  TimeOfDay time1, time2;                                // class instances
  int hours = 19, minutes = 15;                          // integer variables
  time1.setTime(7,35); 
  time2.setTime(hours, minutes);                         // initialize objects
  cout << "First time: "; 
  time1.displayMilitaryTime();                 // message to the first object
  cout << endl << "\nFirst time: "; 
  time1.displayTime();
  cout << endl << "\nSecond time: "; 
  time2.displayMilitaryTime();                 // message to the second object
  cout << endl << "\nSecond time: "; 
  time2. displayTime();
  return 0;
 }
