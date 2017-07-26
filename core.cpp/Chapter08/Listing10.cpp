// Listing 8.10.	Example of direct access to underlying data representation

#include <iostream>          // No encapsulation yet
#include <cstring>
using namespace std;

char buffer[81];  char store[81];             // global data

bool checkParen ()
{ char c, sym; int i, idx; bool valid;
  i = 0; idx = 0; valid = true;           // initialize data
  while (buffer[i] != '\0' && valid)     // end of data or error?
   { c = buffer[i];                      // get next symbol
     if (c=='(' || c=='[')               // is next symbol left?
       { store[idx] = c;  idx++; }       // then save it away
     else if (c==')' || c==']')          // is next symbol right?
       if (idx > 0)                    // does saved symbol exist?
        { idx--;  sym = store[idx];      // get the last symbol
          if (!((sym=='(' && c==')') ||  
	       (sym=='[' && c==']')))        // if they do not match
	         valid = false; }            // then it is an error
       else
        valid = false;             // error if no symbol to match
   i++; }                                // go get next symbol
   if (idx > 0) valid = false;  // unmatched left symbols: an error
   return valid; }                    // return the error status

void checkParenTest(char expression[])          // test harness
{ strcpy(buffer,expression);
  cout << "Expression " << buffer << endl; // print the expression
  if (checkParen())                        // validate it
	  cout << "is valid\n";              // print the result
  else
	  cout << "is not valid\n";
}

int main()                                      // test driver
{ checkParenTest("a=(x[i]+5)*y;");     // first test run: valid
  checkParenTest("a=(x[i)+5]*y;");     // second test run: invalid
  return 0;
  }
