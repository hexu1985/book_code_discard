// Listing 4-2. A conditional statement without the 'else' part.

#include <iostream>
using namespace std;

#define ABSOLUTE_ZERO  -273

int main ()
{ 
  int cels;  
  cout << "\nEnter temperature in Celsius: ";  
  cin >> cels;
  cout << "\nYou entered the value " << cels << endl;
  if (cels < ABSOLUTE_ZERO)
    cout <<"\nThe value " <<cels <<" is invalid\n"           // no ; semicolon
         <<"It is below absolute zero\n";                    // this is one statement
  cout << "Thank you for using this program" <<endl;
  return 0;
 }
