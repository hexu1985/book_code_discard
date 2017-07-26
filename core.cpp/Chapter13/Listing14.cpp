// Listing 13.14	Example of inheritance hierarchy for Account classes

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
 
 class CheckingAccount : public Account {      // derived class
   double fee;
 
 public: 
   CheckingAccount(double initBalance)
   { balance = initBalance;  fee = 0.2; } 
 
   void withdraw(double amount)  // it hides base class method
   { if (balance > amount)
       balance = balance - amount - fee; }
 } ;
 
 int main()
 { 
   CheckingAccount a1(1000);            // derived class object
   a1.withdraw(100);                    // derived class method
   a1.deposit(200);                     // base class method
   cout << " Ending balances\n";
   cout << "   checking account object: " << a1.getBal() <<endl;
   return 0;
   }
