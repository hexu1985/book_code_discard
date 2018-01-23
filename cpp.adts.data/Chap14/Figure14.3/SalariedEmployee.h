/* SalariedEmployee.h ----------------------------------------------------
   Header file for a class SalariedEmployee derived from Employee that
   adds the attributes unique to salaried employees. 
   Operations are:  A constructor and an output operation.
   ----------------------------------------------------------------------*/
#include "Employee.h"

#ifndef SALARIED_EMPLOYEE
#define SALARIED_EMPLOYEE

class SalariedEmployee : public Employee
{
 public:
   SalariedEmployee (long id = 0, string last = "", 
                    string first = "", char initial = ' ',
                    int dept = 0, double salary = 0);
  /*-----------------------------------------------------------------------
    Salaried Employee constructor.
    Preconditions:  None.
    Postconditions: Data members myIdNum, myLastName, myFirstName,
       myMiddleInitial, and myDeptCode are initialized by the Employee
       constructor; mySalary is initialized to salary (default 0).
   -----------------------------------------------------------------------*/ 

  void display(ostream & out) const;
  /*-----------------------------------------------------------------------
    Output function member.
    Precondition:  ostream out is open.
    Postcondition: A text representation of this SalariedEmployee 
        object has been output to out.
   -----------------------------------------------------------------------*/ 

  // ... Other salaried employee operations ...

 private:
  double mySalary;
};

//--- Definition of SalariedEmployee's Constructor
inline SalariedEmployee::SalariedEmployee
                   (long id, string last, string first, char initial,
                    int dept, double sal)
: Employee(id, last, first, initial, dept), 
  mySalary(sal)
{ }

//--- Definition of SalariedEmployee's display()
inline void SalariedEmployee::display(ostream & out) const
{
  Employee::display(out);            //inherited members
  out << "$" << mySalary << endl;    //local members
}
#endif
