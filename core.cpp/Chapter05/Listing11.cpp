// Listing 5.11. Entering input data in the array with overflow protection

#include <iostream>  
#include <cstring>
#include <cstdlib>             // to support atof()
using namespace std;

int main ()
// { const int NUM = 100;       // the size can of course change
{ 
  const int NUM = 3;                   // for debugging only    
  const char LAST[] = "end";    // literal for input termination
  double amount, total, data[NUM];
  char buff[20];  int count; 
  total = 0.0;  count = 0;     // initialize current data
do {                           // do until the user enters "end"
  cout << "Enter amount (or '" << LAST << "' to finish): ";
  cin.get(buff,20); cin.ignore(2000,'\n');
  if (strcmp(buff,LAST)==0) break;   // end of input data
  amount = atof(buff);        // convert to double up to 100 chars 
  if (amount <= 0)             // zero if non-numeric input
    cout << "This value is discarded as incorrect.\n"
         << "Please reenter it correctly.\n";
  else if (count < NUM)
   { total += amount;           // process current data
     data[count] = amount;
     count++; }             
  else 
   { cout << "Out of memory: input is terminated\n";
     break; }
   } while (1 == 1);
  if (strcmp(buff,"end") != 0)
      cout << "The value " << amount << " is not saved\n";
  cout << "\nTotal of " << count << " values is "
       << total << endl;
  if (count == 0) return 0;
  cout << "\nTran no.  Amount\n\n";
  for (int i = 0;  i < count;  i++) 
   { cout.width(4); cout << i+1;
     cout.width(11); cout << data[i] << endl; }
  return 0;
  }
