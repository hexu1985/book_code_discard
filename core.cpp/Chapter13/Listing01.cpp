// Listing 13.1	Example of combining diverse features in the same class Account.

#include <iostream> 
using namespace std;

class Account {

  double balance;                 // for all kinds of accounts
  double rate;                    // for savings account only
  double fee;                     // for checking accounts only

public: 

  Account(double initBalance = 0) // for checking accounts only
  { balance = initBalance; fee = 0.2; } // use fee but not rate

  Account (double initBalance, double initRate)  // for savings
  { balance = initBalance;  rate = initRate; }   // no fee here

  double getBal()
  { return balance; }             // common for both accounts

  void withdraw(double amount)    // common for both accounts 
  { if (balance > amount)
       balance -= amount; }      

  void deposit(double amount)     // common for both accounts
  { balance += amount; }

  void payInterest()              // for savings accounts only
  { balance += balance * rate / 365 / 100; }
  void applyFee()
   { balance -= fee; }            // for checking accounts only
  } ;

int main()
{ 
  Account a1(1000), a2(1000,6.0);  // a1: checking, a2: savings
  cout << "Initial balances: " << a1.getBal() 
       << " " << a2.getBal() << endl;
  a1.withdraw(100);  a2.deposit(100);         // no problem  
  a2.payInterest();  a1.applyFee();           // no errors
  cout << "Ending balances: " << a1.getBal() 
       << " " << a2.getBal() << endl;
  return 0;
  }

