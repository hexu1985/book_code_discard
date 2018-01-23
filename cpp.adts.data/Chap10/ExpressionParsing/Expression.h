/*-- Expression.h ---------------------------------------------------------
  This header file contains the declaration of a class Expression that
  models the parsing of simplified arithmetic expressions given by the
  syntax rules:
      expression --> term + term | term - term | term
      term --> factor * factor | factor / factor | factor
      factor --> (expression) | letter | digit
    
  Basic Operations:
  Constructor:         Constructs a default empty expression
  read():              Inputs string to be checked for a well-formed
                          expression
  isWellFormed():      Checks if entire string is a well-formed expression
                          according to the preceding syntax rules
  isValidExpression(): Checks for a valid expression at a particular
                          position
  isValidTerm():       Checks for a valid term at a particular position
  isValidFactor():     Checks for a valid factor at a particular position
  nextChar():           Gets next nonwhitespace character                       
--------------------------------------------------------------------------*/

#include <iostream>

class Expression
{
 public:
  /*** Function Members ***/
  Expression();
  /*----------------------------------------------------------------------
    Construct an Expression object.

    Precondition:  None.
    Postcondition: myExpr == '#' and myPosition == -1.
   ----------------------------------------------------------------------*/  
  
  bool read(istream & in);
  /*----------------------------------------------------------------------
    Read a string to be checked.

    Precondition:  istream is open.
    Postcondition: A string for myExpr is read from in; true is 
        returned if it the end-of-data signal "#", and false otherwise.
  ----------------------------------------------------------------------*/  
  
  bool isWellFormed();
  /*----------------------------------------------------------------------
    Check if a string is a well-formed expression.

    Precondition:  None.
    Postcondition: True is returned if myExpr is a well-formed expression.
  ----------------------------------------------------------------------*/  

  bool validExpression();
  /*----------------------------------------------------------------------
    Check if myExpr contains a valid expression beginning at myPosition.

    Precondition:  None.
    Postcondition: True is returned if myExpr contains a valid expression
        at myPosition and myPosition is  incremented to the end of this
        expression; otherwise false is returned.
  ----------------------------------------------------------------------*/  

  bool validTerm();
  /*---------------------------------------------------------------------
    Check if myExpr contains a valid  term beginning at myPosition.

    Precondition:  None.
    Postcondition: True is returned if myExpr contains a valid term at
        myPosition and myPosition is incremented to the end of this
        term; otherwise false is returned.
  ----------------------------------------------------------------------*/  

  bool validFactor();
  /*---------------------------------------------------------------------
    Check if myExpr contains a valid  factor beginning at myPosition.

    Precondition:  None.
    Postcondition: True is returned if myExpr contains a valid factor 
        at myPosition and myPosition is incremented to the end of this
        factor; otherwise false is returned.
  ----------------------------------------------------------------------*/  

  char nextChar();
  /*---------------------------------------------------------------------
    Get the next nonwhitespace character in myExpr after myPosition.

    Precondition:  None.
    Postcondition: Next nonwhitespace character in myExpr is returned;
        a semicolon () is returned if there is none; myPosition is
        incremented to the position of this character.
  ----------------------------------------------------------------------*/  

 private:
  /*** Data Members ***/
  string myExpr;
  int myPosition;
};
