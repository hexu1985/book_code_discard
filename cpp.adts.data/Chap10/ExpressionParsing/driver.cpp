/*---------------------------------------------------------------------
    Driver program for the expression parser in class Expression.
 --------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Expression.h"

int main()
{
   for (;;)
   {
 	     Expression expr;
    
      bool done = expr.read(cin);
      if (done) break;
    
      if (expr.isWellFormed())
         cout << "Valid expression\n";
      else
         cout << "Not a valid expression\n";
   }
}
