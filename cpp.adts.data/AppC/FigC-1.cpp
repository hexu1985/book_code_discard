/*------------------------------------------ 
  Program to greet its user.
  Input:  The name of the user
  Output: A personalized greeting
 -----------------------------------------*/

#include <iostream>    // cin, cout, <<, >>
#include <string>      // string
using namespace std;


int main()
{
  cout << "Please enter your first name: ";
  string firstName;
  cin >> firstName;

  cout << "\nWelcome to the world of C++, " 
       << firstName << "!\n";
}
