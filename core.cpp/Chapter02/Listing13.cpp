// Listing 2-13. Your first C++ program with prototypes in a separate file

const double PI = 3.1415926;
// #include "c:\data\cppbook\core c++\chapter 02\display.h"      // prototypes
#include "..\..\core c++\chapter 02\display.h"      // prototypes

int main(void)  
{ 
  double x=PI, y=1; // 
  displayInitialGreeting();                                // function calls
  y = computeSquare(x,y);
  displayResults(y);
  return 0;
}                // end of the function block 
