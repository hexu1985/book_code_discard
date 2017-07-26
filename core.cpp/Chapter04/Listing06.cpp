// Listing 4-6.	Nested conditional statements.

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
  if (orderAmt > SMALL_ORDER)
    if (preferred == 1)
     { cout <<"Discount earned " <<orderAmt*DISCOUNT<<endl; 
       totalAmt = orderAmt * (1 - DISCOUNT); }
    else
       totalAmt = orderAmt; 
  else 
    if (preferred == 0)
      totalAmt = orderAmt + SERVICE_CHARGE;
    else 
      totalAmt = orderAmt; 
  cout << "Total amount: " << totalAmt << endl;
  return 0;
 }
