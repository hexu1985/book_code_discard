// Listing 7.1.	Passing parameters for side effects (bad version)

#include <iostream>  
using namespace std;

void swap (int a1, int a2)              // wrong parameter mode 
{ int temp;
  if (a1 > a2)
  { cout << "Before swap: a1=" << a1 << " a2=" << a2 << endl;
    temp = a1;  a1 = a2;  a2 = temp; 
    cout << "After swap:  a1=" << a1 << " a2=" << a2 << endl; } }

int main ()
{ 
  int x = 84, y = 42;                   // values are out of order
  swap(x,y);             // bad parameter mode; it should not work
  cout << "After call:  x=" << x << " y=" << y << endl;
  return 0;
  }
