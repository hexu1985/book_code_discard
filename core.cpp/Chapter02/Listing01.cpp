#include <iostream>                  // preprocessor directive 
#include <cmath>                     // preprocessor directive
using namespace std;                 // compiler directive
const double PI = 3.1415926;         // definition of a constant
int main(void)                       // function returns integer
{ 
  double x=PI, y=1, z;               // definitions of variables
  cout << "Welcome to the C++ world!" << endl; // function call
  z = y + 1;                         // assignment statement
  y = pow(x,z);                      // function call
  cout << "In that world, pi square is " << y << endl;
  cout << "Have a nice day!" << endl;
  return 0;                          // return statement
}                                    // end of function block
