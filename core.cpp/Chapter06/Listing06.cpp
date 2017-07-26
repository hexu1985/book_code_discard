// Listing 6.6. Using pointers with unnamed heap variables

#include <iostream>
using namespace std;

 int main()
 { 
   int *pi;  char* pc;  // non-initialized pointers
   pi = new int;    // get unnamed space, point the pointer to it
   if (pi == NULL)  // if new fails, it returns zero 
    { cout << "Out of memory\n"; return 0; } // or try to recover
   pc = new char;   // get unnamed space, point the pointer to it
   if (pc == 0)     // necessary precaution
    { cout << "Out of memory\n"; return 0; } // or try to recover
   *pi = 28791;  
   if (*pi > 0) *pc = 'a';     // manipulate unnamed objects
   cout << " integer on the heap:   " << *pi << endl;
   cout << " character on the heap: " << *pc << endl;
   delete pi; delete pc;  // part of heap memory life cycle
   cout << " (after delete) int: " <<*pi <<" char: " <<*pc <<endl;
   return 0;
  }
