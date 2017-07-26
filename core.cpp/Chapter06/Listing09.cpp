// Listing 6.9. Reading transaction data with protection against array overflow

#include <iostream>
#include <iomanip>
using namespace std;
 
 int main ()
 { 
   const int NUM = 3;     // for debugging: it should be larger
   double amount, total = 0, data[NUM];
   int count = 0;   // initialize current data
 do {                        // do until EOF or array overflow
   cout << "Enter amount (or 0 to finish): ";
   cin >> amount;              // get next double from the file
   if (count==NUM || amount==0) break;  // overflow or sentinel
   total += amount;          // process current valid data
   data[count++] = amount;   // and get next input line
    } while (true);
   if (amount != 0)             // was all data read in 
    { cout << "Out of memory: input was terminated\n";
      cout << "The value " << amount << " is not saved" << endl; }
   cout << "\nTotal of " << count << " values is "
        << total << endl;
   if (count == 0) return 0;          // no results if no input
   cout << "\nTran no.  Amount\n\n";  // print the table header
   cout.setf(ios::fixed);    // set up fixed format for double
   cout.precision(2);        // total digits if NO ios::fixed
   for (int i = 0;  i < count;  i++)  // go over the data again
    { cout << setw(4); cout << i+1;              // tran number
      cout << setw(11); cout << data[i] << endl; } // tran value
   return 0;
  }

