/* Employee.h --------------------------------------------------------
                See Figure 14.3 for documentation
  -------------------------------------------------------------------*/
#include <iostream>

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
 public:
   Employee(long id = 0, string last = "", string first = "", 
	        char initial = ' ', int dept = 0);
  //-- See Figure 14.3 for documentation

  virtual void display(ostream & out) const;
  //-- See Figure 14.3 for documentation

  // ... Other employee operations ...

 private:
  long myIdNum;             // Employee's id number
  string myLastName,        //     "      last name
         myFirstName;       //     "      first name
  char myMiddleInitial;     //     "      middle initial
  int myDeptCode;           //     "      department code
  // ... other attributes common to all employees
};


//--- Definition of Employee’s Constructor
inline Employee::Employee(long id, string last, string first, 
                          char initial, int dept)
{
  myIdNum = id;
  myLastName = last;
  myFirstName = first;
  myMiddleInitial = initial;
  myDeptCode = dept;
}

//--- Definition of Employee’s display()
void Employee::display(ostream & out) const
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
