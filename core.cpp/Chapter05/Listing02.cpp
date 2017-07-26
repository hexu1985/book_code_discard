// Listing 5.2. Error is hidden by correct output

#include <iostream>        // or #include <iostream.h>  
using namespace std;

int main()
{ 
   int size[5];
   size[1]=39; size[2]=40; size[3]=41; size[4]=42; size[5]=43;
   for (int i = 1;   i <= 5;  i++) // bad start, bad end
      cout << "  " << size[i]; 
   cout << endl; 
   return 0;
 }
