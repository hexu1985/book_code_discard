// Listing 18.3	Example of a extensive communications between 
// the client and the server code.

#include <iostream> 
#include <cfloat>
using namespace std;

class MSG {
	static char* data [];               // internal static data
public:
	static char* msg(int n)             // public static method
	{ if (n<1 || n > 5)                 // check index validity
	    return data[0];
	  else
          return data[n]; }               // return valid string
} ;

char* MSG::data [] = { "\nBad argument to msg()\n",
"\nZero denominator is not allowed\n\n", // depository of text
"\nNegative denominator: ", 
"Enter numerator and positive\n",
"denominator (any letter to quit): ",
"Value of the fraction:         " 
 } ;                   

inline long inverse(long value, double& answer, char* &msg)
{ answer = (value) ? 1.0/value : DBL_MAX;
  if (answer==DBL_MAX)
    { msg = MSG::msg(1);
      return 0; }                       // zero denominator
  else if (value < 0)
	{ msg = MSG::msg(2);
      return value; }                   // negative denominator
  else
      return 1; }                       // valid denominator

inline long fraction (long n,long d,double& result,char* &msg)
{ long ret = inverse(d, result,msg);    // result = 1.0 / d
  if (ret == 1)                         // valid denominator
    { result = n * result; }            // result = n / d
  return ret; }

int main()
{ 
  while (true)
  { long numer, denom;  double ans;     // numerator/denominator
    char *msg;  long ret;               // error information
    cout << MSG::msg(3) << MSG::msg(4); // prompt user for data
    if ((cin >> numer >> denom) == 0) break; // enter data
	ret = fraction(numer,denom,ans,msg);  // compute answer
    if (ret == 1)
      cout << MSG::msg(5) << ans <<"\n\n";   // valid answer
    else if (ret == 0)
      cout << msg;                           // zero denominator
    else 
      cout << msg << ret << "\n\n"; }        // negative value
  return 0;
  }
