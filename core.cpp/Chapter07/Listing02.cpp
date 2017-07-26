// Listing 7.2.	Passing parameters by pointer (parameter modes are correct)

#include <iostream>  
using namespace std;

void swap (int *a1, int *a2)    // correct parameter mode 
{ int temp;    
  if (a1 > a2) {
    cout << "Before swap: *a1=" << *a1 << " *a2=" << *a2 << endl;
    temp = *a1; *a1 = *a2;  *a2 = temp;   // correct dereferencing
    cout << "After swap:  *a1=" <<*a1 <<" *a2=" <<*a2 << endl; } }

int main ()
{ 
  int x = 82, y = 42;         // values are out of order 
  swap(&x,&y);      // correct parameter mode; it should work
  cout << "After call:  x=" << x << " y=" << y << endl;
  return 0;
  }

