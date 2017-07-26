// Listing 18.2	Example of a program with errors discovered by the server code.

#include <iostream> 
#include <cfloat>
using namespace std;

inline long inverse(long value, double& answer)
{ answer = (value) ? 1.0/value : DBL_MAX;
  if (answer==DBL_MAX)
    { cout << "\nZero denominator is not allowed\n\n";
	  return 0; }                     // zero denominator
  else if (value < 0)
	{ return value; }                 // negative denominator
  else
    return 1; }                       // valid denominator

inline long fraction (long n,long d,double& result,char* &msg)
{ long ret = inverse(d, result);      // result = 1.0 / d
  if (ret == 1)                       // valid denominator
    { result = n * result; }          // result = n / d
  if (ret < 0)
	  msg = "\nNegative denominator: ";
  return ret; }

int main()
{ 
  while (true)
  { long numer, denom;  double ans;   // numerator/denominator
    char *msg;  long ret;             // error information
    cout << "Enter numerator and positive\n"
		<< "denominator (any letter to quit): ";
    if ((cin >> numer >> denom) == 0) break; // enter data
	ret = fraction(numer,denom,ans,msg);  // compute answer
    if (ret == 1)                            // valid answer
	cout << "Value of the fraction:         " << ans <<"\n\n";
    else if (ret < 0)
	cout << msg << ret << "\n\n"; }       // negative value
  return 0;
  }
