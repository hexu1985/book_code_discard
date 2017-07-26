// Listing 2-7. An example of a loop with formatted output

#include <iostream>
#include <iomanip>

using namespace std;

int main (void)
{ 
  int num = 8, square;                                    // num is initialized before loop 
  cout << "Numbers    Their Squares\n\n" << endl << endl; 
  while (num < 12)                                         // num is used as a loop vari-able 
   { square = num * num;  // num is used in the body 
     cout << "  " << num << "       " << square << endl;           // quick and dirty out-put
     num = num + 1;                                        // it is modified at loop end 
                 }                                         // no ';' at end of the block 
  cout << endl << "\nHave a nice day.\n" << endl;          // notice indentation
  return 0;
}
