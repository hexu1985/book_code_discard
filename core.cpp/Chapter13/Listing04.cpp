// Listing 13.4	Example of inheritance hierarchy for Account classes.

#include <iostream> 
using namespace std;

class Account {                     // base class of hierarchy
protected:
  double balance;

public: 
  Account(double initBalance = 0)
  { balance = initBalance; } 

  double getBal()
  { return balance; }               // common for both accounts

  void withdraw(double amount)      // common for both accounts 
  { if (balance > amount)
  balance -= amount; }

  void deposit(double amount)
  { balance += amount; }
} ;

class CheckingAccount : public Account { // first derived class
  double fee;

public: 
  CheckingAccount(double initBalance)
  { balance = initBalance;  fee = 0.2; } // for checking account

  void withdraw(double amount) 
  { if (balance > amount)
      balance = balance - amount - fee; } // unconditional fee
} ;

class SavingsAccount : public Account {  // second derived class
  double rate;

public: 
  SavingsAccount(double initBalance)
  { balance = initBalance;  rate = 6.0; } // savings account

  void payInterest()                      // not for checking
  { balance += balance * rate / 365 / 100; }
} ;

int main()
{ 
  Account a(1000);                      // base class object
  CheckingAccount a1(1000);             // derived class object
  SavingsAccount a2(1000);              // derived class object
  a1.withdraw(100);                     // derived class method
  a2.deposit(100);                      // base class method
  a1.deposit(200);                      // base class method
  a2.withdraw(200);                     // base class method
  a2.payInterest();                     // derived class method
  a.deposit(300);                       // base class method
  a.withdraw(100);                      // base class method
  //a.payInterest();                    // syntax error
  //a1.payInterest();                   // syntax error
  cout << " Ending balances\n   account object:          "
       << a.getBal()<<endl;
  cout << "   checking account object: " << a1.getBal() << endl;
  cout << "   savings account object:  " << a2.getBal() << endl;
  return 0;
  }

