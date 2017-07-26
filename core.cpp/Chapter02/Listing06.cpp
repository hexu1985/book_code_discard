// Listing 2-6. Your first C++ program with a nested statement block

#include <iostream>                          // preprocessor directives 
#include <cmath>   
using namespace std;

const double PI = 3.1415926;                 // definition of a constant

int main(void) 
{ 
  double x=PI, y=1, z;                       // definitions of variables
  cout << "Welcome to the C++ world!" << endl; 
  z = y + 1;   
  y = pow(x,z);
  {                                          // start of statement block
    cout << "In that world, pi square is " << y << endl;
    cout << "Have a nice day!" << endl;
    return 0; 
   }                                         // end of statement block
}                                            // end of function block
