// Listing 6.1. Demonstration of lexical scope for types, parameters, variables

#include <iostream>
using namespace std;

struct Account {                     // global type definition
  long num;     
  double bal; } ;   

double getBalance(Account a)
{ double total = a.bal;              // total in independent scopes
  return total; }                    // return a.bal; is better

int main()
{ 
  typedef int Index;                 // local type definition
  Index const MAX = 5;
  Index i, count = 0;                // integers in dis-guise
  Account a[MAX];  double total = 0;     // data set, its total
  while (true)                       // break on the senti-nel
  { long num[MAX] = { 800123456, 800123123, 800123333, -1 } ;
    double amounts[MAX] = { 1200, 1500, 1800 } ; // data to load
    if (num[count] == -1) break;         // sentinel is found
    a[count].num = num[count];                   // loading data
    a[count].bal = amounts[count];
    count++; } 
    cout << "  Data is loaded\n\n";
  for (i = 0; i < count; i++)
   { long temp = a[i].num;        // temp in independent scopes
     cout << temp << endl; }      // display account numbers
  for (i = 0; i < count; i++)  
   { double temp = a[i].bal;      // temp in independent scopes
     cout << temp << endl; }      // display account balances
  for (i = 0; i < count; i++)
  { total += getBalance(a[i]); } // accumulate total for balances
  cout << endl << "Total of balances $" << total << endl;
  return 0;
 }
