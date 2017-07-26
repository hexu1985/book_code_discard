// Listing 2-2. Your first C++ program with block comments

#include <iostream.h>                /* preprocessor directives */ 
#include <math.h>
#define  PI  3.1415926
int main(void)                       /* function returns integer */
{ 
  double x=PI, y=1, z;               /* definitions of variables */
  cout << "Welcome to the C++ world!" << endl; /* function call */
  z = y + 1;                         /* assignment statement */
  y = pow(x,z);                      /* function call */
  cout << "In that world, pi square is " << y << endl;
  cout << "Have a nice day!" << endl;
  return 0;                          /* return statement */
}                                    /* end of the function block */
