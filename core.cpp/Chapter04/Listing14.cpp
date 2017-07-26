// Listing 4-14. The while loop with the assignment in the loop condition . 

#include <iostream>
using namespace std;

int main ()
{ 
  char ch;  int count = 0, spaces = 0; // initialize counters
  cout << "\nType a sentence, press Enter\n";
  while ((ch = cin.get()) != '\n')   // change current data
   { cout << ch;                     // process next symbol
     if (ch == ' ') spaces++;        // OK for a single line
     count++; }
  cout << "\nTotal number of characters " << count << endl;
  cout << "Number of spaces is " << spaces << endl; 
  return 0;
} 
