// Listing 6.5. Using pointers with ordinary named variables

#include <iostream>
using namespace std;

 int main()
 { 
   int i;  int *pi;  char *pc;   // non-initialized point-ers
   pi = &i;               // this assignment turns the pointer to i
   *pi = 502;             // this is ok, but so is  i = 15020; 
   if (*pi>0) *pc = 28791;  // how good is it? same as if(i>0) i=28791
   pc = (char*) &i;       // some compilers do not require need the cast 
   int a1 = *pi;            // access to i through pointer
   int a2 = *pc;            // access to i through pointer
   cout << " i as decimal: " << i << endl
        << " i as hex: " << hex << i << endl;
   cout << " i through int pointer:   " << dec << a1 << endl;
   cout << " i through char pointer:  " << a2 << endl;
   cout << " i through char pointer in hex: " << hex << a2 << endl;
   return 0;  
  }
