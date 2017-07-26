// Listing 13.15	Example of inheritance hierarchy for Account classes.

 #include <iostream> 
 using namespace std;
 
 class Account {                              // base class
 protected:
   double balance;
 public: 
   Account(double initBalance = 0)
   { balance = initBalance; } 
   double getBal()               // inherited without change
   { return balance; }
   void withdraw(double amount)  // overwritten in derived class
   { if (balance > amount)
       balance -= amount; }
   void deposit(double amount)   // inherited without change
   { balance += amount; }
 } ;
 
 class CheckingAccount : public Account {     // derived class
   double fee;
 
 public: 
   CheckingAccount(double initBalance)
   { balance = initBalance;  fee = 0.2; } 
 
   void withdraw(double amount)
   { if (balance > amount)
       balance = balance - amount - fee; }
 
   void deposit(double amount)    // hides the base class method
   { Account::deposit(amount); }  // call to a base function 
 
   void deposit(double amount, double fee) // hides base method
   { balance = balance + amount - fee - CheckingAccount::fee; } 
 } ;
 
 int main()
 { 
   CheckingAccount a1(1000);            // derived class object
   a1.withdraw(100);                    // derived class method
   a1.deposit(200);                     // existing client code
   a1.deposit(200,5);                   // new client code
   cout << " Ending balances\n";
   cout << "   checking account object: " << a1.getBal() <<endl;
   return 0;
   }
