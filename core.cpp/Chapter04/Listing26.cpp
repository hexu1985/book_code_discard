// Listing 4-26.	Calls to the library function exit() .

#include <iostream.h>
#include <stdlib.h>

void main(void)
{ 
  double op1, op2; char ch;
  cout << "Enter operand, operator, another operand: ";
  cin >> op1 >> ch >> op2;
  if (ch == '+')      // first case
    cout << "Result is " << op1 + op2 << endl;
  else if (ch == '*')     // second case
    cout << "Result is " << op1 * op2 << endl;
  else if (ch == '-')     // third case
    cout << "Result is " << op1 - op2 << endl;
  else if (ch == '/')     // fourth case: more complex
    { if (op2 != 0.0)
        cout << "Result is " << op1 / op2 << endl;
      else
        cout << "Division by zero" << endl; }
  else                    // fifth case: error
   { cout << "Illegal operator" << endl;
     exit(EXIT_FAILURE); }  // tell them we are bust
  exit(EXIT_SUCCESS);       // tell them we are OK
 }
