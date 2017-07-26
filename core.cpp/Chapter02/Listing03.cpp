// Listing 2-3. Your first C++ program with code blocked out: error

#include <iostream.h>                /* preprocessor directives */ 
#include <math.h>
#define  PI  3.1415926
int main(void)                       /* function returns integer */
{ 
  double x=PI, y=1, z;               /* definitions of variables */
  cout << "Welcome to the C++ world!" << endl; /* function call */
/* beginning of the block to be cut out
  z = y + 1;                         /* assignment statement */
  y = pow(x,z);                      /* function call */
  cout << "In that world, pi square is " << y << endl;
                         */         // end of the block to be cut out
  cout << "Have a nice day!" << endl;
  return 0;                          /* return statement */
}                                    /* end of the function block */
