// Listing 8.13.	Encapsulating temporary storage store[]

#include <iostream>          // Encapsulation with info hiding
#include <cstring>
using namespace std;

struct Store { 
  char a[81];                   // array for temporary storage
  int idx; } ;                  // index to first available slot

void initStore (Store &s)
  { s.idx = 0; }                // initialize the empty store

bool isEmpty (const Store& s) 
  { return (s.idx == 0); }      // check whether the store is empty

void saveSymbol (Store &s, char x)
{ s.a[s.idx++] = x; }           // save the symbol in the store
  
char getLast(Store &s)  
{  return s.a[--s.idx]; }       // get back the last symbol saved 
   
bool isLeft (char c)
{ return (c=='(' || c=='['); }   // check if it is a left symbol

bool isRight (char c)          
{ return (c==')' || c==']'); }   // check if it is a left symbol

bool symbolsMatch (char c, char sym)       
{ return (sym=='('&&c==')')||(sym=='['&&c==']');} // do they match?

bool checkParen (char buffer[])        // expression in parameter
{ Store store;                         // array is encapsulated
  char c,sym; int i; bool valid;
  i = 0; initStore(store); valid = true;  // initialize data
  while (buffer[i] != '\0' && valid)      // end of data or error?
   { c = buffer[i];                   // get next symbol
     if (isLeft(c))                   // is next symbol left?
	 { saveSymbol(store,c); }         // then save it away
     else if (isRight(c))             // is next symbol right?
       if (!isEmpty(store))           // does saved symbol exist?
        { sym = getLast(store);       // get the last symbol
          if (!symbolsMatch(c,sym))   // if they do not match
	        valid = false; }          // then it is an error
       else
        valid = false;        // error if no saved symbol to match
   i++; }                                // go get next symbol
   if (store.idx>0) valid=false;  // error: unmatched left symbols
   return valid; }                    // return the error status

void checkParenTest(char expression[])
{ cout << "Expression " << expression << endl; // print expression
  if (checkParen(expression))                  // validate it
	  cout << "is valid\n";                 // print the result
  else
	  cout << "is not valid\n"; }

int main()
{ cout << endl << endl;
  checkParenTest("a=(x[i]+5)*y;");     // first test run: valid
  checkParenTest("a=(x[i)+5]*y;");     // second test run: invalid;
  checkParenTest("a=(x(i]+5]*y;");     // third test run: invalid;
  cout << endl << endl;
  return 0;
  }
