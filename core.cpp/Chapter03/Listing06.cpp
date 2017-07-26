// Listing 3.6	Demonstration of implicit type conversions.

#include <iostream> 
using namespace std;

int main()
 { 
   float fahr, celsius;  
   cout << "Please enter the value is Celsius: ";
   cin >> celsius;   
   fahr = 1.8 * celsius + 32;  // conversions ?
   cout << "Value in Fahrenheit is " << fahr << endl;
   return 0;
   }
