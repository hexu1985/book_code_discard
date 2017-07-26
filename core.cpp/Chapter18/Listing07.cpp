// Listing 18.7	Example of throwing class objects rather than built-in values.

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

class ZeroDenom {
	char *msg;           // data to be carried to error handler
public:
	ZeroDenom ()         // it is called by the throw statement
	{ msg = MSG::msg(1); }
	void print () const  // it is called by the catch block
	{ cout << msg; }
} ;

class NegativeDenom {
    long val;                 // private data for exception info
    char* msg;
public:
    NegativeDenom(long value) // conversion constructor
           : val(value), msg(MSG::msg(2)) { }
    char* getMsg() const
	{ return msg; }
    long getVal() const       // public methods to access data
	{ return val; }
} ;

inline void inverse(long value, double& answer) 
          throw (ZeroDenom, NegativeDenom)
{ answer = (value) ? 1.0/value : DBL_MAX;
  if (answer==DBL_MAX)
    throw ZeroDenom();
  if (value < 0)
    throw NegativeDenom(value); }
  
inline void fraction (long numer, long denom, double& result)
          throw (ZeroDenom, NegativeDenom)
{ inverse(denom, result);              // result = 1.0 / denom
  result = numer * result; }           // result = numer/denom
    
int main()
{ 
  while (true)
  { long numer, denom;  double ans;     // numerator/denominator
    cout << MSG::msg(3) << MSG::msg(4); // prompt user for data
    if ((cin >> numer >> denom) == 0) break; // enter data
    try {
      fraction(numer,denom,ans);             // compute answer
      cout << MSG::msg(5) << ans <<"\n\n"; } // valid answer
    catch (const ZeroDenom& zd)              // zero denominator
    { zd.print(); } 
    catch (const NegativeDenom &nd)          // negative value
    { cout << nd.getMsg() << nd.getVal() << "\n\n"; } 
   }  
  return 0;
  }
