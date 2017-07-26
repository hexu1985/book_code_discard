// Listing 6.7. Using malloc() and free() for memory management

 #include <iostream>
 #include <cstdlib>        // header for malloc() and free()
 using namespace std;
 
 int main()
 { 
   int *pi;  char* pc;      // non-initialized pointers
   pi = (int*) malloc(sizeof(int));    // get unnamed space
   if (pi == NULL)          // if malloc() fails, it returns zero 
     { cout << "Out of memory\n"; return 0; } // or try to recover
   pc = (char*) malloc(sizeof(char));  // get unnamed space
   if (pc == NULL)          // necessary precaution
     { cout << "Out of memory\n"; return 0; } // or try to recover
   *pi = 28791;  
   if (*pi > 0) *pc = 'a';  // manipulate unnamed objects
   cout << " integer on the heap:   " << *pi << endl;
   cout << " character on the heap: " << *pc << endl;
   free(pi);  free(pc);
   cout << " (after delete) int: " <<*pi <<" char: " <<*pc <<endl; 
   return 0;
  }
