/* HourlyEmployee.h -------------------------------------------------------
   Header file for a class HourlyEmployee derived from Employee that
   adds the attributes unique to hourly employees. 
   Operations are:  A constructor and an output operation.
   -----------------------------------------------------------------------*/
#include "Employee.h"

#ifndef HOURLY_EMPLOYEE
#define HOURLY_EMPLOYEE

class HourlyEmployee : public Employee
{
 public:
   HourlyEmployee (long id = 0, string last = "", string first = "", 
		   char initial = ' ', int dept = 0, double weeklyWage = 0,
		   double hoursWorked = 0, double overTimeFactor = 1.5);
   /*----------------------------------------------------------------------
    Hourly Employee constructor.
    Preconditions:  None.
    Postconditions: Data members myIdNum, myLastName, myFirstName,
       myMiddleInitial, and myDeptCode are initialized by the Employee
       constructor; myWeeklyWage is initialized to weeklyWage (default 
       0), myHoursWorked to hoursWorked (default 0), and 
       myOverTimeFactor to overTimeFactor (default 1.5).
   -----------------------------------------------------------------------*/ 

  virtual void display(ostream & out) const;
  /*-----------------------------------------------------------------------
    Output function member.
    Precondition:  ostream out is open.
    Postcondition: A text representation of this HourlyEmployee 
        object has been output to out.
   -----------------------------------------------------------------------*/ 

  // ... Other hourly employee operations ...

 private:
  double myWeeklyWage,
         myHoursWorked,
         myOverTimeFactor;
};

//--- Definition of HourlyEmployee's Constructor
inline HourlyEmployee::HourlyEmployee 
                 (long id, string last, string first, char initial,
                  int dept, double weeklyWage, double hoursWorked, 
                  double overTimeFactor)
: Employee(id, last, first, initial, dept),
  myWeeklyWage(weeklyWage), myHoursWorked(hoursWorked),
  myOverTimeFactor(overTimeFactor)
{ }

//--- Definition of HourlyEmployee's display()
inline void HourlyEmployee::display(ostream & out) const
{
  Employee::display(out);              //inherited members
  out << "$" << myWeeklyWage << endl   //local members
      << myHoursWorked << endl 
      << myOverTimeFactor << endl;
}
#endif
