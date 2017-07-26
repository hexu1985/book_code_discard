// Listing 4-1. An example of the A conditional statement .

#include <iostream>
using namespace std;

int main ()
{ 
  int cels;  
  cout << "\nEnter temperature in Celsius: ";  
  cin >> cels;
  cout << "\nYou entered the value " << cels << endl;
  if (cels < -273)
    cout <<"\nThe value " <<cels <<" is invalid\n" // no ;
         <<"It is below absolute zero\n"; // one statement
  else 
    cout <<cels<<" is a valid temperature\n"; 
  cout << "Thank you for using this program" <<endl;
  return 0;
 }
