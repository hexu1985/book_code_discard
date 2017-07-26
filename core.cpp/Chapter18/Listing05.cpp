// Listing 18.5	Example of claiming, throwing and catching exceptions.

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

inline void inverse(long value, double& answer) 
          throw (char*, long)
{ answer = (value) ? 1.0/value : DBL_MAX;
  if (answer==DBL_MAX)
	  throw MSG::msg(1);
  if (value < 0)
	  throw value; }
  
inline void fraction (long numer, long denom, double& result)
          throw (char*)
{ try {
    inverse(denom, result); }          // result = 1.0 / denom
  catch (long val)                     // negative value is OK
	{ cout << MSG::msg(2) << val << "\n\n"; }
  result = numer * result; }           // result = numer / denom

int main()
{ 
  while (true)
  { long numer, denom;  double ans;     // numerator/denominator
    cout << MSG::msg(3) << MSG::msg(4); // prompt user for data
    if ((cin >> numer >> denom) == 0) break; // enter data
    try {
      fraction(numer,denom,ans);             // compute answer
      cout << MSG::msg(5) << ans <<"\n\n"; } // valid answer
    catch (char* str)                        // zero denominator
    { cout << str; } 
   }  
  return 0;
  }
