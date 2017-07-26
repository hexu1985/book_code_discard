// Listing 4-16. The do-while loop for character input

#include <iostream>
using namespace std;

int main ()
{ 
  char ch;  int count = 0, spaces = 0; // initialize data
  cout << "\nType a sentence, press Enter\n";
do {  
    ch = cin.get();              // change current data
    if (ch != '\n')              // check for end of data
     { cout << ch;
       if (ch == ' ') spaces++;  // process current data
       count++; }
    } while (ch != '\n');        // evaluate current data
  cout << "\nTotal number of characters " << count << endl;
  cout << "Number of spaces is " << spaces << endl; 
  return 0;
}
