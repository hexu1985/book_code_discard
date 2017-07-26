// Listing 4-13. The while loop with the prime read for reading characters.

#include <iostream>
using namespace std;

int main ()
{ 
  char ch;  int count = 0, spaces = 0; // initialize counters
  cout << "\nType a sentence, press Enter\n";
  ch = cin.get();                      // prime read for the loop
  while (ch != '\n')                   // no semicolon after the condition 
   { cout << ch;                       // process data: echo, check, count
     if (ch == ' ')  
       spaces++; 
     count++;
     ch = cin.get(); }                 // change current data 
  cout << "\nTotal number of characters " << count << endl;
  cout << "Number of spaces is " << spaces << endl;
  return 0;
 }
