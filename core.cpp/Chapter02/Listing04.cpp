// Listing 2-4. Your first C++ program with definitions in the middle of code

#include <iostream>                  // preprocessor directive 
#include <cmath>                     // preprocessor directive
using namespace std;                 // compiler directive
const double PI = 3.1415926;         // definition of a constant
int main(void)                       // function returns integer
{ 
  cout << "Welcome to the C++ world!" << endl; // function call
  double y=1, z;                     // definitions of variables
  z = y + 1;                         // assignment statement
  double x=PI;                       // definition of variable
  y = pow(x,z);                      // function call
  cout << "In that world, pi square is " << y << endl;
  cout << "Have a nice day!" << endl;
  return 0;                          // return statement
}                                    // end of function block
