// Listing 4-20. The 'for' loop with assignment in its ContinuingExpr.

#include <iostream>
using namespace std;

int main ()
{ 
  char ch; int count, spaces;                    // no initialization is done here
  cout << "\nType a sentence, press Enter\n";
  for (count=0, spaces=0; (ch=cin.get())!='\n'; count++)  // a lot of processing
   { cout << ch;                                 // process next input symbol
     if (ch == ' ') spaces++; }
  cout << "\nTotal number of characters " << count << endl;
  cout << "Number of spaces is " << spaces << endl;
  return 0; 
 } 
