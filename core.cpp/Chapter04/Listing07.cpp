// Listing 4-7.	An optimized nested conditional statement.

#include <iostream>
using namespace std;

int main ()
{ 
  const double DISCOUNT = 0.1, SMALL_ORDER = 20;
  const double SERVICE_CHARGE = 2.0;
  double orderAmt, totalAmt;  int preferred;
  cout << "\nPlease enter the order amount: ";  
  cin >> orderAmt;
  cout << "Enter 1 if preferred customer, 0 otherwise: ";
  cin >> preferred;
  totalAmt = orderAmt;                  // do it the second way
  if (orderAmt > SMALL_ORDER)   // change totalAmt if not a small order
    if (preferred == 1)
     { cout <<"Discount earned " <<orderAmt*DISCOUNT<<endl;
       totalAmt = orderAmt * (1 - DISCOUNT); }
  else                                  // this is an optical illusion
    if (preferred == 0)        // for small order, check customer status
      totalAmt = orderAmt + SERVICE_CHARGE; 
  cout << "Total amount: " << totalAmt << endl;
  return 0;
 }
