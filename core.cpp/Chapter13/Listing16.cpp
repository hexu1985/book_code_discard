// Listing 13.16	Example of enhanced inheritance hierarchy for Account classes

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
 } ;                             // no changes to existing class
 
 class CheckingAccount : public Account {     // derived class
 protected:
   double fee;
 
 public: 
   CheckingAccount(double initBalance = 0)
   { balance = initBalance;  fee = 0.2; } 
 
   void withdraw(double amount)  // hides the base class method
   { if (balance > amount)
       balance = balance - amount - fee; }
 } ;                             // no changes to existing class
 
 class InternationalAccount : public CheckingAccount { // great!
 public: 
   InternationalAccount(double initBalance)
   { balance = initBalance; } 
 
   void deposit(double amount, double fee) // hides base method
   { balance = balance + amount - fee - CheckingAccount::fee; } 
 } ;                          // work is pushed to a new class
 
 int main()
 {
   CheckingAccount a1(1000);          // derived class object
   a1.withdraw(100);                  // derived class method
   a1.deposit(200);                   // base class method
   InternationalAccount a2(1000);     // new server object
   a2.deposit(200,5);                 //derived class method
   cout << " Ending balances\n";
   cout << "   First checking account object:  " 
        << a1.getBal() << endl;
   cout << "   Second checking account object: " 
        << a2.getBal() << endl; 
   return 0;
   }
