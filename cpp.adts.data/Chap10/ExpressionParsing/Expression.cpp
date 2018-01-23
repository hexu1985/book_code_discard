//--- Expression.cpp ---------------------------------------------

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "Expression.h"


//--- Definition of constructor
Expression::Expression()
: myExpr("#"), myPosition(-1)
{ }


//--- Definition of read()
bool Expression::read(istream & in)
{
  cout << "\nEnter arithmetic expression (# to stop): ";
  getline(in, myExpr);
  return (myExpr == "#");
}

//--- Definition of isWellFormed()
bool Expression::isWellFormed()
{
   return validExpression() && myPosition == myExpr.length() - 1;
}


//--- Definition of validExpression() 
bool Expression::validExpression()
{
  if (validTerm())
  {
    char symbol = nextChar();
    if (symbol == '+' || symbol == '-')
      return validTerm();
    // else "unget a character"
    myPosition--;
    return true;
  }
  // else
  return false;
}

//--- Definition of validTerm() 
bool Expression::validTerm() 
{
  if (validFactor())
  {
    char symbol = nextChar();
    if (symbol == '*' || symbol == '/')
      return validFactor();
    // else "unget a character"
    myPosition--;
    return true;
  }
  // else
  return false;
}

//--- Definition of validFactor() 
bool Expression::validFactor() 
{
  char symbol = nextChar();
  if (symbol == '(')            // a left parenthesis
  {
    if (validExpression())
    {
       symbol = nextChar();
       return symbol == ')';
    }
    else
      return false;
  }
  // else
  return isalnum(symbol);
}

//--- Definition of nextChar()
char Expression::nextChar()
{
  char ch;
  for (;;)
  {
    myPosition++;
    if (myPosition == myExpr.length())
      ch = ';';
    else
      ch = myExpr[myPosition];
    if (!isspace(ch)) 
      return ch;
  }
}
