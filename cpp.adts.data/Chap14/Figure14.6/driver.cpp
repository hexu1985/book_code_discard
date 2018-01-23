/*--------------------------------------------------------------------------
      Driver program to process a list of pointers to employee objects.
 -------------------------------------------------------------------------*/

#include <iostream>
#include <list>
using namespace std;
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "Manager.h"

int main()
{
  Employee * ptr;
  list<Employee*> empList;
  ptr = new Employee(11111, "Doe", "John", 'J', 11);
  empList.push_back(ptr);
  ptr = new SalariedEmployee(22222, "Smith", "Mary", 'M', 22, 59900);
  empList.push_back(ptr); 
  ptr = new HourlyEmployee(33333, "Jones", "Jay", 'J', 33, 15.25, 40);
  empList.push_back(ptr); 
  ptr = new Manager(22222, "Brown", "Betty", 'B', 25, 60000, 13);
  empList.push_back(ptr); 

  for (list<Employee*>::iterator it = empList.begin();
                                 it!= empList.end(); it++)
  {
    ptr = *it;
    cout << *ptr << endl;
  }
 
}
