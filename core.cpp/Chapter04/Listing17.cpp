// Listing 4-17. The do-while loop with assignment within a conditional statement

#include <iostream>
using namespace std;

int main ()
{ 
  char ch;  int count = 0, spaces = 0; // initialize data
  cout << "\nType a sentence, press Enter\n";
  do {  
    if ((ch = cin.get())!= '\n') // change current data
     { cout << ch;
       if (ch == ' ') spaces++;  // process current data
       count++; }
    } while (ch != '\n');        // evaluate current data
  cout << "\nTotal number of characters " << count << endl;
  cout << "Number of spaces is " << spaces << endl;
  return 0; 
 }
