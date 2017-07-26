// Listing 2-8. Your first C++ program with one server function

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926;

void displayInitialGreeting()                            // function header
{  
   cout << "Welcome to the C++ world!\n" << endl;    // its body
  }                                            // end of the function block

int main(void)  
{ 
  double x=PI, y=1, z;  
  displayInitialGreeting();                             // function call
  z = y + 1; 
  y = pow(x,z); 
//  cout << "In that world, pi square is " << y << endl;
//  cout << "Have a nice day!" << endl;
  return 0;
    }                                          // end of the function block

