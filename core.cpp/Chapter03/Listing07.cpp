// Listing 3.7.	Loss of precision in integer computations.

#include <iostream> 
using namespace std;

int main()
 { 
   double fahr, celsius;  
   cout << "Please enter the value is Celsius: ";
   cin >> celsius;   
   fahr = 9 / 5 * celsius + 32;  // accuracy ?
   cout << "Value in Fahrenheit is " << fahr << endl;
   return 0;
   }
