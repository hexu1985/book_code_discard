// Listing 4-28.	Calculator with the switch statement (better program).

#include <iostream.h>
#include <stdlib.h>

void main(void)
{ double op1, op2; char ch;
  cout << "Enter operand, operator, another operand: ";
  cin >> op1 >> ch >> op2;
  switch(ch) {                        // mandatory braces  
   case '+': cout << "Result is " << op1 + op2 << endl;
             break;
   case '*': cout << "Result is " << op1 * op2 << endl;
             break;
   case '-': cout << "Result is " << op1 - op2 << endl;
             break;
   case '/': if (op2 != 0.0)
               cout << "Result is " << op1 / op2 << endl;
             else
               cout << "Division by zero" << endl;
             break;
  default:  cout << "Illegal operator" << endl;
            break; }            // break is optional here
  exit(EXIT_SUCCESS);           // next statement
}
