// Listing 16.2	Example of handling class Account with overloaded operator methods.

#include <iostream>   
using namespace std;

class Account {                     // base class of hierarchy
protected:
  double balance;                   // protected data
  char *owner;
public: 

  Account(const char* name, double initBalance)   // general
  { owner = new char[strlen(name)+1];   // allocate heap space
    if (owner == 0) { cout << "\nOut of memory\n";  exit(0); }
	strcpy(owner, name);            // initialize data fields
	balance = initBalance; } 

  double getBal() const             // common for both accounts
  { return balance; }               

  const char* getOwner() const      // protect data from changes
  { return owner; }                 

  void operator -= (double amount) 
  { balance -= amount; }           // pull responsibility up

  void operator += (double amount)
  { balance += amount; }           // increment unconditionally
} ;

Account* createAccount(const char* name, double bal)
{ Account* a = new Account(name,bal);    // account on the heap
  if (a == 0) { cout << "\nOut of memory\n";  exit(0); }
  return a; }

void processRequest(Account* a[], const char name[])
{ int i;  int choice;  double amount;
  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(2);
  for (i=0;  a[i] != 0;  i++)
  { if (strcmp(a[i]->getOwner(),name)==0) // search for name
     { cout << "Account balance: " << a[i]->getBal() << endl; 
       cout <<"Enter 1 to deposit, 2 to withdraw, 3 to cancel: ";
       cin >> choice;                     // transaction type
       if (choice != 1 && choice != 2) break;
	   cout << "Enter amount: ";
	   cin >> amount;                     // transaction amount
	   switch (choice) {
	     case 1: *a[i] += amount;   // a[i]->operator+=(amount);
                    break;
	     case 2: if (amount <= a[i]->getBal())
                     *a[i] -= amount; // a[i]->operator-=(amount);
                    else
				         cout << "Insufficient funds\n"; 
                    break; }          // end of switch scope
	   cout << "New balance: "<< a[i]->getBal() << endl; 
       break; } }                     // end of search loop
    if (a[i] == 0)
	{ cout << "Customer is not found\n"; } }
	
void printList (Account* a[])
{ cout << "Customer List:\n\n";
  for (int i=0;  a[i] != 0;  i++)
  { cout.setf(ios::left, ios::adjustfield); cout.width(30);
    cout << a[i]->getOwner();
    cout.setf(ios::right, ios::adjustfield); cout.width(10);
    cout << a[i]->getBal() << endl; }
  cout << endl; }

int main()
{ 
  Account* accounts[100];  char name[80];    // program data
  accounts[0] = createAccount("Jones",5000); // create objects
  accounts[1] = createAccount("Smith",3000);
  accounts[2] = createAccount("Green",1000);
  accounts[3] = createAccount("Brown",1000);
  accounts[4] = 0;
  printList(accounts);
  while (true)                               // process requests
  { cout << "Enter customer name ('exit' to exit): ";
    cin >> name;                             // accept name
	if (strcmp(name,"exit")==0) break;       // test for end
	processRequest(accounts, name);          // next transaction
	}
  return 0;
  }
