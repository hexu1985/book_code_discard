// Listing 4-3. A conditional statement with compound branches .

#include <iostream>
using namespace std;

const int ABSOLUTE_ZERO = -273;

int main ()
{ 
  int cels;  
  cout << "\nEnter temperature in Celsius: ";  
  cin >> cels;
  cout << "\nYou entered the value " << cels << endl;
  if (cels < ABSOLUTE_ZERO)
   { cout <<"\nThe value " <<cels <<" is invalid\n";
     cout <<"It is below absolute zero\n"; } // a block
  else 
   { cout <<cels<<" is a valid temperature\n"; // a block 
     cout << "You can proceed with calculations\n"; }
  cout << "Thank you for using this program" <<endl;
  return 0;
 }
