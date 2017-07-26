// Listing 5.10. Filling the contiguous array with transaction data

#include <iostream>  
#include <cstring>
#include <cstdlib>
using namespace std;

int main ()
{ 
  const int NUM = 100;       // the size can of course change
  double total, amount, data[NUM];  int count;
  char buff[20];
  total = 0.0;  count = 0;   // initialize current data
do {                         // do until the user enters "end"
  cout << "Enter amount (or 'end' to finish): ";
  cin.get(buff,20); cin.ignore(2000,'\n');
//  cout << "You entered '" << buff << "'" << endl; // debugging
  if (strcmp(buff,"end")==0) break;
  amount = atof(buff);       // convert to double up to 100 chars
//  cout << "Amount: " << amount << endl;   // debugging aid
  if (amount <= 0)           // zero if non-numeric input
    cout << "This value is discarded as incorrect.\n"
         << "Please reenter it correctly.\n";
  else
   { total += amount;            // process current data
     data[count] = amount;
     count++; }             
   } while (1 == 1);
  cout << "\nTotal of " << count << " values is "
       << total << endl;
  if (count == 0) return 0;
  cout << "\nTran no.  Amount\n\n";
  for (int i = 0;  i < count;  i++) 
   { cout.width(4); cout << i+1;
     cout.width(11); cout << data[i] << endl; }
  return 0;
  }
