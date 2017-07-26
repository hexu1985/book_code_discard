// Listing 4-4. Checking values for inequality (incorrect version)

#include <iostream>
using namespace std;

int main ()
{ 
  int num;  
  cout << "\nPlease enter a non-zero integer: ";  
  cin >> num;
  if (num > 0)                                    // it should be (num != 0)
   { cout <<"\nYou followed the instructions correctly";
     cout <<"\nThe inverse of this value is " << 1.0/num; 
     cout <<"\nThe square of this value is " << num * num; }
  else 
     cout <<"\nYou did not follow the instructions";
  cout << "\nThank you for using this program" <<endl;
  return 0;
 }
