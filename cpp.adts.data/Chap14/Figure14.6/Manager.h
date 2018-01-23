/* Manager.h --------------------------------------------------------------
   Header file for a class Manager derived from SalariedEmployee that adds
   the attributes unique to managers. 
   Operations are:  A constructor and a virtual output operation.
   -----------------------------------------------------------------------*/
#include "SalariedEmployee.h"

#ifndef MANAGER
#define MANAGER

class Manager : public SalariedEmployee
{
public:
  Manager(long id = 0, string last = "", string first = "",
    char initial = ' ', int dept = 0, double sal = 0, int numEmps = 0);
   /*----------------------------------------------------------------------
    Manager constructor.
    Preconditions:  None.
    Postconditions: Data members myIdNum, myLastName, myFirstName,
       myMiddleInitial, myDeptCode, mySalary are initialized by the
       SalariedEmployee constructor; myNumEmps is initialized to 
       numEmps (default 0).
   -----------------------------------------------------------------------*/ 

  virtual void display(ostream & out) const;
  /*-----------------------------------------------------------------------
    Output function member.
    Precondition:  ostream out is open.
    Postcondition: A text representation of this Manager object has been
        output to out.
   -----------------------------------------------------------------------*/ 
 
 // ... Other Manager operations ...

private:
  int myNumEmps;
};

//--- Definition of Manager's Constructor
inline Manager::Manager(long id, string last, string first, char initial, 
                        int dept, double sal, int numEmps)
: SalariedEmployee(id, last, first, initial, dept, sal), 
  myNumEmps(numEmps) 
{}

//--- Definition of Manager's display()
inline void Manager::display(ostream & out) const 
{ 
  SalariedEmployee::display(out);
  out << myNumEmps << endl;
}
#endif