// Listing 5.1. Erroneous scan over the array

#include <iostream>         // or #include <iostream.h>
using namespace std;

int main()
{ 
   int size[5] = { 39, 40, 41, 42, 43 };
   for (int i = 1;   i <= 5;  i++)  // bad start, bad end
      cout << "  " << size[i]; 
   cout << endl; 
   return 0;
 }
