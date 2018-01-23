/*-------------------------------------------------------------------------
  Find an approximate solution of the equation f(x) = 0 in a given
  interval, using the bisection method.
 
  Input:   Desired accuracy of approximation, endpoints of an 
           interval containing a solution
  Output:  Prompts to the user and the approximate solution
 
  Notes:   
  1. The solution will be within desiredAccuracy of the exact 
     solution.
  2. To find the solution for a different f(x), redefine f() below.
-------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

double f(double x)
{
   return x*x*x + x - 5;       // the function f for which the
}                              // equation f(x) = 0 is being solved

//----------------------------------------------------------------

typedef double (* FunctionPointer)(double);

double bisector(FunctionPointer fPtr, 
                double left, double right, double accuracy);

int main()
{
  cout << "\nThis program uses the bisection method to find an"
          "\napproximate solution to the equation f(x) = 0.\n";
  double desiredAccuracy;  // the accuracy desired

  cout << "\nEnter the accuracy desired (e.g. .001): ";
  cin >> desiredAccuracy;
  double left,             // left and right endpoints
         right;            //   of (sub)interval containing a solution
  do                       // get the interval containing a solution
  {
    cout << "Enter the x-values of interval containing solution: ";
    cin >> left >> right;
  }
  while (f(left) * f(right) >= 0.0);

  double                   // find the approximate solution
     solution = bisector(f, left, right, desiredAccuracy);
  cout << "\n--> "<< solution
       << " is an approximate solution of F(x) = 0, to within "
       << desiredAccuracy << endl;
}

double bisector(FunctionPointer fPtr, 
                double left, double right, double accuracy)
/*-------------------------------------------------------------------------
  Function to perform the bisection algorithm.
 
  Receive:  FPtr, (a pointer to) a function for which a zero is to be found.
            left, the left endpoint of the original interval
            right, the right endpoint of the original interval
            accuracy, the desired accuracy of the approximation
  Return:   midPt, the middle of the final interval
 -------------------------------------------------------------------------*/
{
  double width = right - left,      // the interval width
         midPt,                     // the midpoint of the interval
         f_Mid;                     // value of fPtr at midpoint
  while (width/2.0 > accuracy)
  {    
    midPt = (left + right) / 2.0;   //   compute midpoint
    f_Mid = fPtr(midPt);            //   compute function at midpoint
    if (fPtr(left) * f_Mid < 0.0 )  //   solution is in left half
      right = midPt;
    else                            //   solution is in right half
      left = midPt;

    width /= 2.0;                   //   split the interval
  }

  return midPt;
}
