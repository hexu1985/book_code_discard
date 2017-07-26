// Listing 7.4.	Passing parameters by reference (robust method)

#include <iostream>  
using namespace std;

void swap (int &a1, int &a2)       // correct parameter mode 
{ int temp;    
  if (a1 > a2) {                   // no dereference operator
    cout << "Before swap: a1=" << a1 << " a2=" << a2 << endl;
    temp = a1; a1 = a2;  a2 = temp;   // no dereferencing
    cout << "After swap:  a1=" << a1 << " a2=" << a2 << endl; } }

int main ()
{ int x = 82, y = 42;             // values are out of order
//{ int x = 42, y = 84;           // values are ordered
  swap(x,y);                      // this is beautiful!
  cout << "After call:  x=" << x << " y=" << y << endl;
  return 0;
  }

