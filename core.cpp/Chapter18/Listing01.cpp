// Listing 18.1	Example of a program with error processing in the client code.

#include <iostream> 
using namespace std;

inline void inverse(long value, double& answer)
{ answer = 1.0/value; }              // answer = 1/value

inline void fraction (long numer,long denom,double& result)
{ inverse(denom, result);            // result = 1.0 / denom
  result = numer * result; }         // result = numer/denom

int main()
{ 
  while (true)                     // infinite loop
  { long numer, denom; double ans; // numerator and denominator
    cout << "Enter numerator and positive\n"
		 << "denominator (any letter to quit): ";
    if ((cin >> numer >> denom) == 0) break; // enter data
    if (denom > 0) {                         // correct input
      fraction(numer,denom,ans);             // compute result
      cout << "Value of the fraction:         " << ans <<"\n\n";
	}
    else if (denom == 0)                     // invalid result
      cout << "\nZero denominator is not allowed\n\n";
    else
      cout << "\nNegative denominator: " << denom <<"\n\n"; }
  return 0;
  }
