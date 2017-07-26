// Listing 7.5.	Passing structures as reference parameters

#include <iostream>  
using namespace std;

struct Account {
  long num;     
  double bal; } ;   
  
void printAccounts(const Account &a1, const Account &a2)
{ cout << "First account:  No. " << a1.num 
       << "  balance " << a1.bal << endl;
  cout << "Second account: No. " << a2.num 
       << "  balance " << a2.bal << endl; }
  
void swapAccounts (Account &a1, Account &a2)
{ Account temp;
  if (a1.num > a2.num)
  { temp = a1;  a1 = a2;  a2 = temp; } }
                    
int main()
{ 
  Account x, y;
  x.num = 800123456;  x.bal = 1200;                    
  y.num = 800123123;  y.bal = 1500;
  cout << "Before swap\n";
  printAccounts(x,y);
  swapAccounts(x,y);
  cout << "After swap\n";
  printAccounts(x,y); 
  return 0;
  }

