// Listing 8.12.	A better example of encapsulation

#include <iostream>             // Better distribution of knowledge
#include <cstring>
using namespace std;

bool isLeft (char c)
{ return (c=='(' || c=='['); }   // check if it is a left symbol

bool isRight (char c)          
{ return (c==')' || c==']'); }   // check if it is a left symbol

bool symbolsMatch (char c, char sym)       
{ return (sym=='('&&c==')')||(sym=='['&&c==']');} // do they match?

bool checkParen (char buffer[])       // expression in parameter
{ char store[81];                     // local array
  char c,sym; int i, idx; bool valid;
  i = 0; idx = 0; valid = true;           // initialize data
  while (buffer[i] != '\0' && valid)      // end of data or error?
   { c = buffer[i];                   // get next symbol
     if (isLeft(c))                   // is next symbol left?
       { store[idx] = c;  idx++; }    // then save it away
     else if (isRight(c))             // is next symbol right?
       if (idx > 0)                   // does saved symbol exist?
        { sym = store[--idx];         // get the last symbol
          if (!symbolsMatch(c,sym))   // if they do not match
	        valid = false; }          // then it is an error
       else
        valid = false;        // error if no saved symbol to match
   i++; }                                // go get next symbol
   if (idx > 0) valid = false; // unmatched left symbols: an error
   return valid; }                    // return the error status

void checkParenTest(char expression[])
{ cout << "Expression " << expression << endl; // print expression
  if (checkParen(expression))                  // validate it
	  cout << "is valid\n";                 // print the result
  else
	  cout << "is not valid\n"; }

int main()
{ 
  checkParenTest("a=(x[i]+5)*y;");     // first test run: valid
  checkParenTest("a=(x[i)+5]*y;");     // second test run: invalid;
  checkParenTest("a=(x(i]+5]*y;");     // third test run: invalid;
  return 0;
  }
