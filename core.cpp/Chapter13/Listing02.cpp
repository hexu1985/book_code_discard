// Listing 13.2	Example of run-time test of correctness of client code.

#include <iostream> 
using namespace std;

enum Kind { CHECKING, SAVINGS } ; // constants for account kind

class Account {
  double balance;
  double rate, fee;
  Kind tag;                       // tag field for object kind

public: 
  Account(double initBalance, Kind kind)
  { balance = initBalance;  tag = kind;  // set the tag field
    if (tag == CHECKING)
       fee = 0.2;                        // for checking account
    else if (tag == SAVINGS)
       rate = 6.0; }                     // for savings account

  double getBal()
  { return balance; }              // common for both accounts

  void withdraw(double amount)     // common for both accounts 
  { if (balance > amount)
      { balance -= amount;
        if (tag == CHECKING)       // for checking accounts only
           balance -= fee; } }

  void deposit(double amount)
  { balance += amount; }

  void payInterest()               // for savings account only
  { if (tag == SAVINGS)
     balance += balance * rate / 365 / 100;
    else if (tag == CHECKING)   
     cout << " Checking account: illegal operation\n";  }
  } ;

int main()
{ 
  Account a1(1000,CHECKING);       // a1 is checking account
  Account a2(1000,SAVINGS);        // a2 is savings account
  cout << " Initial balances: " << a1.getBal() 
       << "  " << a2.getBal() << endl;
  a1.withdraw(100);  a2.deposit(100);      // no problem
  a1.payInterest();  a2.payInterest();     // is this any good?
  cout << " Ending balances: " << a1.getBal() 
       << "  " << a2.getBal() << endl; 
  return 0;
  }

