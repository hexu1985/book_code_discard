// Listing 5.3. Error in one place corrupts memory in another

#include <iostream.h>  

void main()
{ 
  int a[3]; int size[5];
  a[1]=11; a[2]=12; a[3]=13;     // this is a victim of corruption
  size[1]=39; size[2]=40; size[3]=41; size[4]=42; size[5]=43;
   for (int i = 1;   i <= 5;  i++) // bad start, bad end
      cout << "  " << size[i]; 
   cout << endl;
   for (i = 0;   i < 3;  i++)    // correct start, correct end
      cout << "  " << a[i];
   cout << endl; 
 }
