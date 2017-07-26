// Listing 2-9. Your first C++ program with two server functions

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926536;

void displayInitialGreeting()                     // function header
{ cout << "Welcome to the C++ world!\n" << endl; } // its body

void displayResults(double y)               // function header
{ cout << "In that world, pi square is n" << y << endl;
  cout << "Have a nice day!\n" << endl; }                // its body

int main(void)  
{ 
  double x=PI, y=1, z;  
  displayInitialGreeting();                       // function call
  z = y + 1; 
  y = pow(x,z); 
  displayResults(y);                              // another function call
  return 0;
     }  
