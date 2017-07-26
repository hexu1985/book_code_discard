// Listing 5.4. Example of manipulating a two-dimensional array

#include <iostream.h>  

void main()
{ 
  const int ROWS = 2, COLS = 3;
  int m[ROWS][COLS] = { { 10, 20, 30 }, { 40, 50, 60 } };
  for (int i=0; i < ROWS; i++)   // this is done once for each row
   { for (int j=0; j<COLS; j++)  // the whole loop for each index i
        cout << "  " << m[i][j];
     cout << endl; }     // end of row: done once for each index i
  }
