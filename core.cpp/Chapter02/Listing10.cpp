// Listing 2-10. Your first C++ program with three server functions

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926;

void displayInitialGreeting()                          // void returnfunction header
{ cout << "Welcome to the C++ world!" << endl; }       // function body

double computeSquare(double x, double y)               // non-void return
{ double z;                                            // a local variable
  z = y + 1; 
  y = pow(x,z); 
  return y; }                                         // mandatory return statement

void displayResults(double y)                         // function header
{ cout << "In that world, pi square is " << y << endl;
  cout << "Have a nice day!" << endl; }                  // function body

int main(void)  
{ 
  double x=PI, y=1; // z;  -- z is not needed anymore
  displayInitialGreeting();                         // function call
  y = computeSquare(x,y);                           // another function call
  displayResults(y);                                // yet another function call
  return 0;
     }  
