// Listing 18.9	Examples of pointer conversions using standard casts.

#include <iostream> 
using namespace std;

class Account {                     // base class of hierarchy
protected:
  double balance;                   // protected data
  int pin;                          // identification number
  char owner[40];
public: 
  Account(const char* name, int id, double bal)   // general
  { strcpy(owner, name);            // initialize data fields
    balance = bal; pin = id; } 
  operator double () const          // common for both accounts
  { return balance; }
  operator int () const 
  { return pin; }
  operator const char* () const
  { return owner; }
  void operator -= (double amount) 
  { balance -= amount; }
  void operator += (double amount)
  { balance += amount; }           // increment unconditionally
} ;

int main()
{ 
  double *pd, d=20.0; int i = 20, *pi = &i;
  pd = (double*) pi;
  cout << "i=" << *pd << "  i=" << *pi <<endl;
  Account a1("Jones",1122,5000);   // create objects
  pd = (double*)(&a1);
  cout << "balance = " << *pd << endl;   
  *pd = 10000;                     // change data member
  cout << "balance = " << *pd << endl;
  return 0;
  }
