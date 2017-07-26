// Listing 5.5. Using a one-dimensional array to implement a matrix

#include <iostream>  
using namespace std;

int main()
{ 
  const int ROWS = 2, COLS = 3;
  int m[ROWS * COLS] = { 10, 20, 30, 40, 50, 60 }; // same size
  for (int i=0; i < ROWS; i++) 
   { for (int j=0; j < COLS; j++)
        cout << "  " << m[i*COLS + j];       // do it hard way
     cout << endl; }     // end of row: done once for each index i
  return 0;
  }
