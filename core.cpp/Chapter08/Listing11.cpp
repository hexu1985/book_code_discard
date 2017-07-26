// Listing 8.11.	Example of encapsulation with shared knowledge

#include <iostream>             // Bad distribution of knowledge
#include <cstring>
using namespace std;

char buffer[81];  char store[81];

bool isLeft (int i)
{ char c = buffer[i];            // get symbol from buffer
  return (c=='(' || c=='['); }   // check if it is a left symbol

bool isRight (int i)          
{ char c = buffer[i];            // get symbol from buffer 
  return (c==')' || c==']'); }   // check if it is a right symbol

bool symbolsMatch (int idx, int i)       
{ char sym = store[idx], c = buffer[i]; // get two symbols to match 
  return (sym=='('&&c==')')||(sym=='['&&c==']');} // do they match?

bool checkParen ()
{ char c; int i, idx; bool valid;
  i = 0; idx = 0; valid = true;           // initialize data
  while (buffer[i] != '\0' && valid)      // end of data or error?
   { c = buffer[i];                   // get next symbol
     if (isLeft(i))                   // is next symbol left?
       { store[idx] = c;  idx++; }    // then save it away
     else if (isRight(i))             // is next symbol right?
       if (idx > 0)                   // does saved symbol exist?
        { idx--;                      // get the last symbol
          if (!symbolsMatch(idx,i))   // if they do not match
	        valid = false; }          // then it is an error
       else
        valid = false;       // error if no saved symbol to match
   i++; }                                // go get next symbol
   if (idx > 0) valid = false; // unmatched left symbols: an error
   return valid; }                    // return the error status

void checkParenTest(char expression[])            // test harness
{ strcpy(buffer,expression);
  cout << "Expression " << buffer << endl; // print the expression
  if (checkParen())                        // validate it
	  cout << "is valid\n";              // print the result
  else
	  cout << "is not valid\n"; }

int main()                                       // test driver
{ 
  checkParenTest("a=(x[i]+5)*y;");     // first test run: valid
  checkParenTest("a=(x[i)+5]*y;");     // second test run: invalid
  return 0;
  }
