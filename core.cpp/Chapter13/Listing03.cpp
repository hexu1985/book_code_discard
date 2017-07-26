// Listing 13.3	Example of separate classes for different subtypes of objects.

#include <iostream> 
using namespace std;

class CheckingAccount {
  double balance;
  double fee;                             // no interest rate

public: 
  CheckingAccount(double initBalance)
  { balance = initBalance;  fee = 0.2; }  // a checking account

  double getBal()
  { return balance; }                // common for both accounts

  void withdraw(double amount) 
  { if (balance > amount)
      balance = balance - amount - fee; } // unconditional fee

  void deposit(double amount)
  { balance += amount; }
} ;

class SavingsAccount {
  double balance;
  double rate;                            // no checking fee

public: 
  SavingsAccount(double initBalance)
  { balance = initBalance;  rate = 6.0; } // a savings account

  double getBal()
  { return balance; }               // common for both accounts

  void withdraw(double amount)      // common for both accounts 
  { if (balance > amount)
      balance -= amount; }

  void deposit(double amount)
  { balance += amount; }

  void payInterest()                // for savings account only
  { balance += balance * rate / 365 / 100; }
} ;

int main()
{ 
  CheckingAccount a1(1000);                     // a1: checking
  SavingsAccount a2(1000);                      // a2: savings
  cout << " Initial balances: " << a1.getBal() 
       << "  " << a2.getBal() << endl;
  a1.withdraw(100);  a2.deposit(100);           // no problem
  //a1.payInterest();           // this is a syntax error now!!
  a2.payInterest();                             // this is ok
  cout << " Ending balances: " << a1.getBal() 
       << "  " << a2.getBal() << endl; 
  return 0;
  }

