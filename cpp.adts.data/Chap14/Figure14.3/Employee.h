/* Employee.h --------------------------------------------------------------
   Header file for a class Employee that encapsulates the attributes common
   to all employees.
   Operations are:  A constructor and an output operation.
   -----------------------------------------------------------------------*/
#include <iostream>

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
 public:
   Employee(long id = 0, string last = "", string first = "", 
	        char initial = ' ', int dept = 0);
  /*-----------------------------------------------------------------------
    Employee constructor.
    Preconditions:  None.
    Postconditions: myIdNum is initialized to id (default 0), myLastName 
        to last (default empty string), myFirstName to first (default 
        empty string), myMiddleInitial to initial (default blank char),
        and myDeptCode to dept (default 0). 
    ----------------------------------------------------------------------*/ 

  void display(ostream & out) const;
  /*-----------------------------------------------------------------------
    Output function member.
    Precondition:  ostream out is open.
    Postcondition: A text representation of this Employee object has 
        been output to out.
  ------------------------------------------------------------------------*/ 

  // ... Other employee operations ...

 private:
  long myIdNum;             // Employee's id number
  string myLastName,        //     "      last name
         myFirstName;       //     "      first name
  char myMiddleInitial;     //     "      middle initial
  int myDeptCode;           //     "      department code
  // ... other attributes common to all employees
};


//--- Definition of Employee's Constructor
inline Employee::Employee(long id, string last, string first, 
                          char initial, int dept)
{
  myIdNum = id;
  myLastName = last;
  myFirstName = first;
  myMiddleInitial = initial;
  myDeptCode = dept;
}

//--- Definition of Employee's display()
inline void Employee::display(ostream & out) const
{
  out << myIdNum << ' ' << myLastName << ", "       
      << myFirstName << ' ' << myMiddleInitial << "  " 
      << myDeptCode << endl;
}

//--- Definition of output operator <<
inline ostream & operator<<(ostream & out, const Employee & emp)
{
  emp.display(out);
  return out;
};

#endif
