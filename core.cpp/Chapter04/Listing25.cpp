// Listing 4-25.	A simplified primitive calculator.

#include <iostream>
using namespace std;

void main(void)

{ 
  double op1, op2; char ch;
  cout << "Enter operand, operator, another operand: ";
  cin >> op1 >> ch >> op2;
  if (ch == '+')
    cout << "Result is " << op1 + op2 << endl;
  else
    if (ch == '*')
      cout << "Result is " << op1 * op2 << endl;
    else
      if (ch == '-')
        cout << "Result is " << op1 - op2 << endl;
      else 
        if (ch == '/')
          if (op2 != 0.0)
            cout << "Result is " << op1 / op2 << endl;
          else
            cout << "Division by zero" << endl;
        else
          cout << "Illegal operator" << endl; 
}
