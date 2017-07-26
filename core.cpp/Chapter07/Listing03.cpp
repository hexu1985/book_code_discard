// Listing 7.3.	Passing parameters by pointer (corrected dereferencing)

#include <iostream>  
using namespace std;

void swap (int *a1, int *a2)    // correct parameter mode 
{ int temp;    
  if (*a1 > *a2) {              // Oh, boy
    cout << "Before swap: *a1=" << *a1 << " *a2=" << *a2 << endl;
    temp = *a1; *a1 = *a2;  *a2 = temp;   // correct dereferencing
    cout << "After swap:  *a1=" <<*a1 <<" *a2=" <<*a2 << endl; } }

int main ()
//{ int x = 82, y = 42;         // values are out of order
{ int x = 42, y = 84;           // values are ordered
  swap(&x,&y);      // correct parameter mode; it should work
  cout << "After call:  x=" << x << " y=" << y << endl;
  return 0;
  }

