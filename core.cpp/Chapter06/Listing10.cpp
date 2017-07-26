// Listing 6.10. Reading data into an array allocated on the heap

#include <iostream>
#include <iomanip>
using namespace std;
 
 int main ()
 { 
   const int NUM = 3;     // for debugging:it should be more
   double amount, total = 0, *data;
   int count = 0, size = NUM;   // initialize current data
   data = new double[size];     // initial array on the heap
 do {                     // do until zero is entered 
   cout << " Enter amount (or 0 to finish): ";
 cin >> amount;           // get next double value
   if (amount == 0) break;  // stop when sentinel appears
   if (count == size)        // out of space, ask for more
    { size = size * 2;                    // make it conspicuous
      double *q = new double[size]; // double array size
      if (q == 0)
 	{ cout <<" Out of heap memory: input was terminated" <<endl;
          break; }
      else {
      cout << "More memory allocated: size = " << size << endl;
      for (int i=0; i < count; i++) // copy old data
        q[i] = data[i];      // use subscript notation
	  delete [] data;        // do not forget to free old data
      data = q; } }          // hook up main pointer
   total += amount;          // process current valid data
   data[count++] = amount;   // and get next input value
    } while (true);
   if (amount != 0)              // and what is this for?
    { cout << "Out of memory: input was terminated\n"; 
      cout << "The value " << amount << " is not saved" << endl; }
   cout << "\n Total of " << count << " values is "
        << total << endl;
   if (count == 0) return 0;            // no results if no input
   cout << "\n Tran no. Amount\n\n";  // print the table header
   cout.setf(ios::fixed);     // set up fixed format for double
   cout.precision(2);         // total digits if NO ios::fixed
   for (int i = 0;  i < count;  i++)  // go over the data again
    { cout << setw(4); cout << i+1;            // tran number
      cout << setw(11); cout << data[i] << endl; } // tran value
   return 0;
  }

