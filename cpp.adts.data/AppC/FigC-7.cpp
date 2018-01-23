/*-------------------------------------------------------------------------
  Program to compute wages for several employees.
  Written at Doofus Univ. by Joe Somebody for CPSC 31416.

  Input:  Id-number, number of dependents, hours worked, and hourly rate
            for each of several employees
  Output: Id-number, hours worked, gross pay, taxes withheld, and net pay       
--------------------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
using namespace std;

// FUNCTION PROTOTYPES

void instruct();
void getEmployeeInfo(int & empNumber, int & dependents,
                     double & hours, double & rate, bool & done);
double grossWages(int dependents, double hours, double rate);
void computeNetPay(double grossPay, int dependents,
                   double & tax, double & netPay);
void printEmpInfo(int idNumber, double hours, double grossPay,
                  double taxes, double netPay);

int main()
{
  int idNumber,              // employee's id-number
      numDependents;         //   number of dependents
  double hoursWorked,        //   hours worked for this pay period
         hourlyRate,         //   dollars per hour
         grossPay,           //   gross pay (before taxes)
         taxWithheld,        //   amount of tax withheld
         netPay;             //   grossPay - taxWithheld
  bool endOfData;            // signals end of data
  instruct();
  for (;;)
  {
    getEmployeeInfo(idNumber, numDependents,
                    hoursWorked, hourlyRate, endOfData);
    if (endOfData) break;
    grossPay = grossWages(numDependents, hoursWorked, hourlyRate);
    computeNetPay(grossPay, numDependents, taxWithheld, netPay);
    printEmpInfo(idNumber, hoursWorked, grossPay, taxWithheld, netPay);
  }
}
// FUNCTION DEFINITIONS
//    If these were placed before main(), the prototypes could be 
//    omitted. This is not usually done, however.

void instruct()
/*-------------------------------------------------------------------------
  Display instructions to the user.

  Output: Instructions
 -------------------------------------------------------------------------*/
{
  cout 
    << "This program computes gross pay, tax withheld, and net pay for "
    << "employees.\nWhen prompted, enter employee's id-number (enter "
    << "0 to stop).  Then enter:"
    << "\n\t# of dependents   hours worked   hourly rate:"
    << "\nseparated by spaces.\n";
}

void getEmployeeInfo(int & empNumber, int & dependents,
                     double & hours, double & rate, bool & finis)
/*-------------------------------------------------------------------------
  Get employee information and/or signal there is no more.

  Input:     Id-number, # of dependents, hours worked, and hourly rate
  Pass back: The four input values (via parameters)
             done is true if end of data was signaled, false otherwise
 -------------------------------------------------------------------------*/
{
  cout << "\nEnter employee number (0 to stop): ";
  cin >> empNumber;                       // get employee number
  finis = (empNumber == 0);
  if (finis) return;                      // if end of data, return
                                          // else get other info
  cout << "Enter # of dependents, hours worked, and hourly rate for "
       << empNumber << ": ";
  cin >> dependents >> hours >> rate;
}

double grossWages(int dependents, double hours, double rate)
/*-------------------------------------------------------------------------
  Compute gross wages as determined by number of hours employee worked 
  plus a dependency allowance for each dependent.

  Receive:  Number of dependents, hours worked, hourly rate
  Return:   Gross wages
 -------------------------------------------------------------------------*/
{
  const double DEP_ALLOWANCE = 100; // bonus per dependent
  double wages;                     // wages earned
  if (hours <= 40)                  // no overtime
    wages = hours * rate;
  else                              // overtime
    wages = 40 * rate + 1.5 * rate * (hours - 40);

                                   // return wages + allowance for deps
  return wages + DEP_ALLOWANCE * dependents;
}

void computeNetPay(double grossPay, int dependents,
                   double & tax, double & netPay)
/*-------------------------------------------------------------------------
  Compute taxes withheld and net pay as gross pay minus taxes withheld.

  Receive:  Gross pay and number of dependents
  Return:   Taxes withheld and net pay (via parameters)
 -------------------------------------------------------------------------*/
{
  const double
    DEDUCTION = 25.00,        // deduction per dependent
    TAX_RATE = 0.12;          // withholding rate
  tax = TAX_RATE * (grossPay - DEDUCTION * dependents);
  if (tax < 0)                // check if any tax to be withheld
    tax = 0;

  netPay = grossPay - tax;    // compute net pay
}

void printEmpInfo(int idNumber, double hours, double grossPay,
                  double taxes, double netPay)
/*-------------------------------------------------------------------------
  Display employee information

   Receive:  Employee's id number, hours worked, gross pay, taxes withheld,
               and net pay
   Output:   These values with appropriate labels.
 -------------------------------------------------------------------------*/
{
  cout << setprecision(2) << setiosflags(ios::showpoint | ios::fixed)
       << "Employee " << idNumber << ":\n"
       << "\tHours worked:    " << setw(6) << hours << endl
       << "\tGross Pay:      $" << setw(6) << grossPay << endl
       << "\tTaxes withheld: $" << setw(6) << taxes << endl
       << "\tNet Pay:        $" << setw(6) << netPay << endl;
}
