// Listing 2-11. Incorrect C++ program with functions following the function calls

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926;

int main(void)  
{ 
  double x=PI, y=1; 
  displayInitialGreeting();                          // syntax error
  y = computeSquare(x,y);                            // another syntax error
  displayResults(y);                                 // and another syntax error
  return 0;
    } 

void displayInitialGreeting()                        // function definitions
{ cout << "Welcome to the C++ world!" << endl; }     // function body

double computeSquare(double base, double exponent)
{ double power = exponent + 1;                        // a local variable
  return pow(base,power); }                           // return statement
 
void displayResults(double y)
{ cout << "In that world, pi square is " << y << endl;
  cout << "Have a nice day!" << endl; }               // function body

