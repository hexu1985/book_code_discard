// Listing 4-27.	Calculator with the switch statement (bad program) .

#include <iostream.h>
#include <stdlib.h>

void main(void)
{ 
  double op1, op2; char ch;
  cout << "Enter operand, operator, another operand: ";
  cin >> op1 >> ch >> op2;
  switch(ch) {                        // mandatory braces  
   case '+': cout << "Result is " << op1 + op2 << endl;
   case '*': cout << "Result is " << op1 * op2 << endl;
   case '-': cout << "Result is " << op1 - op2 << endl;
   case '/': if (op2 != 0.0)
               cout << "Result is " << op1 / op2 << endl;
             else
               cout << "Division by zero" << endl;
  default:  cout << "Illegal operator" << endl;
            exit(EXIT_FAILURE); }  // mandatory braces
  exit(EXIT_SUCCESS);       // next statement
}
